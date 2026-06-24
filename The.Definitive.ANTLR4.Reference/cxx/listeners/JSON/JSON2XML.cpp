#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <memory>

#include <antlr4-runtime.h>
#include "JSONLexer.h"
#include "JSONParser.h"
#include "JSONBaseListener.h"

using namespace antlr4;
using namespace antlr4::tree;

/*
{
    "description" : "An imaginary server config file",
    "logs" : {"level":"verbose", "dir":"/var/log"},
    "host" : "antlr.org",
    "admin": ["parrt", "tombu"]
    "aliases": []
}

to

<description>An imaginary server config file</description>
<logs>
    <level>verbose</level>
    <dir>/var/log</dir>
</logs>
<host>antlr.org</host>
<admin>
    <element>parrt</element> <!-- inexact -->
    <element>tombu</element>
</admin>
<aliases></aliases>
 */

class XMLEmitter : public JSONBaseListener {
private:
    std::map<ParseTree*, std::string> xml;
    
public:
    std::string getXML(ParseTree* ctx) {
        auto it = xml.find(ctx);
        if (it != xml.end()) {
            return it->second;
        }
        return "";
    }
    
    void setXML(ParseTree* ctx, const std::string& s) {
        xml[ctx] = s;
    }
    
    void exitJson(JSONParser::JsonContext* ctx) override {
        setXML(ctx, getXML(ctx->children[0]));
    }
    
    void exitAnObject(JSONParser::AnObjectContext* ctx) override {
        std::stringstream buf;
        buf << "\n";
        for (auto pctx : ctx->pair()) {
            buf << getXML(pctx);
        }
        setXML(ctx, buf.str());
    }
    
    void exitEmptyObject(JSONParser::EmptyObjectContext* ctx) override {
        setXML(ctx, "");
    }
    
    void exitArrayOfValues(JSONParser::ArrayOfValuesContext* ctx) override {
        std::stringstream buf;
        buf << "\n";
        for (auto vctx : ctx->value()) {
            buf << "<element>";  // conjure up element for valid XML
            buf << getXML(vctx);
            buf << "</element>";
            buf << "\n";
        }
        setXML(ctx, buf.str());
    }
    
    void exitEmptyArray(JSONParser::EmptyArrayContext* ctx) override {
        setXML(ctx, "");
    }
    
    void exitPair(JSONParser::PairContext* ctx) override {
        std::string tag = stripQuotes(ctx->STRING()->getText());
        auto vctx = ctx->value();
        std::stringstream buf;
        buf << "<" << tag << ">" << getXML(vctx) << "</" << tag << ">\n";
        setXML(ctx, buf.str());
    }
    
    void exitObjectValue(JSONParser::ObjectValueContext* ctx) override {
        // analogous to String value() {return object();}
        setXML(ctx, getXML(ctx->object()));
    }
    
    void exitArrayValue(JSONParser::ArrayValueContext* ctx) override {
        setXML(ctx, getXML(ctx->array()));  // String value() {return array();}
    }
    
    void exitAtom(JSONParser::AtomContext* ctx) override {
        setXML(ctx, ctx->getText());
    }
    
    void exitString(JSONParser::StringContext* ctx) override {
        setXML(ctx, stripQuotes(ctx->getText()));
    }
    
    static std::string stripQuotes(const std::string& s) {
        if (s.empty() || s[0] != '"') return s;
        return s.substr(1, s.length() - 2);
    }
};

std::unique_ptr<ANTLRFileStream> makeANTLRFileStream(const std::string& fileName) {
    auto input = std::make_unique<ANTLRFileStream>();
    input->loadFromFile(fileName);
    return input;
}

int main(int argc, char** argv) {
    std::string inputFile;
    if (argc > 1) {
        inputFile = argv[1];
    }
    
    std::unique_ptr<ANTLRInputStream> input;
    if (!inputFile.empty()) {
        input = makeANTLRFileStream(inputFile);
    } else {
        input = std::make_unique<ANTLRInputStream>(std::cin);
    }
    JSONLexer lexer(input.get());
    CommonTokenStream tokens(&lexer);
    JSONParser parser(&tokens);
    parser.setBuildParseTree(true);
    
    auto tree = parser.json();
    
    // 显示树形结构（可选）
    // std::cout << tree->toStringTree(&parser) << std::endl;
    
    ParseTreeWalker walker;
    XMLEmitter converter;
    walker.walk(&converter, tree);
    
    std::cout << converter.getXML(tree) << std::endl;
    
    return 0;
}
