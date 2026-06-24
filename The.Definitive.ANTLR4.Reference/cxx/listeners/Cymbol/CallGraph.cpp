#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

#include "antlr4-runtime.h"
#include "CymbolLexer.h"
#include "CymbolParser.h"
#include "CymbolBaseListener.h"

using namespace antlr4;

struct Graph {
    // 使用std::set保持节点唯一性和有序性
    std::set<std::string> nodes;
    // 使用std::multimap实现一对多映射
    std::multimap<std::string, std::string> edges;

public:
    void edge(const std::string& source, const std::string& target) {
        edges.insert({source, target});
    }

    std::string toString() const {
        std::ostringstream oss;
        oss << "edges: {";
        bool first = true;
        for (const auto& edge : edges) {
            if (!first) oss << ", ";
            oss << edge.first << "->" << edge.second;
            first = false;
        }
        oss << "}, functions: {";
        first = true;
        for (const auto& node : nodes) {
            if (!first) oss << ", ";
            oss << node;
            first = false;
        }
        oss << "}";
        return oss.str();
    }

    std::string toDOT() const {
        std::ostringstream buf;
        buf << "digraph G {\n";
        buf << "  ranksep=.25;\n";
        buf << "  edge [arrowsize=.5]\n";
        buf << "  node [shape=circle, fontname=\"ArialNarrow\",\n";
        buf << "        fontsize=12, fixedsize=true, height=.45];\n";
        buf << "  ";
        for (const auto& node : nodes) {
            buf << node << "; ";
        }
        buf << "\n";
        
        for (const auto& edge : edges) {
            buf << "  " << edge.first << " -> " << edge.second << ";\n";
        }
        buf << "}\n";
        return buf.str();
    }
};

class FunctionListener : public CymbolBaseListener {
private:
    Graph graph;
    std::string currentFunctionName;

public:
    void enterFunctionDecl(CymbolParser::FunctionDeclContext* ctx) override {
        currentFunctionName = ctx->ID()->getText();
        graph.nodes.insert(currentFunctionName);
    }

    void exitCall(CymbolParser::CallContext* ctx) override {
        std::string funcName = ctx->ID()->getText();
        // map current function to the callee
        graph.edge(currentFunctionName, funcName);
    }

    Graph& getGraph() {
        return graph;
    }
};

std::unique_ptr<ANTLRFileStream> makeANTLRFileStream(const std::string& fileName) {
    auto input = std::make_unique<ANTLRFileStream>();
    input->loadFromFile(fileName);
    return input;
}

int main(int argc, char* argv[]) {
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

    CymbolLexer lexer(input.get());
    CommonTokenStream tokens(&lexer);
    CymbolParser parser(&tokens);

    parser.setBuildParseTree(true);
    tree::ParseTree* tree = parser.file();

    // 显示树结构（文本形式）
    // std::cout << tree->toStringTree(&parser) << std::endl;

    // 遍历解析树
    tree::ParseTreeWalker walker;
    FunctionListener collector;
    walker.walk(&collector, tree);

    std::cout << collector.getGraph().toString() << std::endl;
    std::cout << collector.getGraph().toDOT() << std::endl;

    return 0;
}
