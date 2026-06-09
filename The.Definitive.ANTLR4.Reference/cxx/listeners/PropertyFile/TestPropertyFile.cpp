#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <memory>

#include "antlr4-runtime.h"
#include "PropertyFileLexer.h"
#include "PropertyFileParser.h"
#include "PropertyFileBaseListener.h"

using namespace antlr4;
using namespace antlr4::tree;

// 通用打印函数，适用于任意键值类型的 unordered_map
template<typename K, typename V>
void printUnorderedMap(const std::unordered_map<K, V>& map) {
    std::cout << "{";
    bool first = true;
    for (const auto& pair : map) {
        if (!first) {
            std::cout << ", ";
        }
        std::cout << pair.first << ":" << pair.second;
        first = false;
    }
    std::cout << "}" << std::endl;
}

// Listener 类
class PropertyFileLoader : public PropertyFileBaseListener {
public:
    std::unordered_map<std::string, std::string> props;

    void exitProp(PropertyFileParser::PropContext* ctx) override {
        std::string id = ctx->ID()->getText();
        std::string value = ctx->STRING()->getText();
        props[id] = value;
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
    PropertyFileLexer lexer(input.get());
    CommonTokenStream tokens(&lexer);
    PropertyFileParser parser(&tokens);
    tree::ParseTree* tree = parser.file();

    ParseTreeWalker walker;
    PropertyFileLoader loader;
    walker.walk(&loader, tree);

    printUnorderedMap(loader.props);

    return 0;
}
