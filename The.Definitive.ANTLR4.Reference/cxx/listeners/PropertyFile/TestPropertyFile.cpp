#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <memory>

#include "antlr4-runtime.h"
#include "PropertyFileLexer.h"
#include "PropertyFileParser.h"
#include "PropertyFileBaseListener.h"
#include "ANTLRInputStream.h"
#include "CommonTokenStream.h"
#include "tree/ParseTree.h"

using namespace antlr4;
using namespace antlr4::tree;

// 有序的哈希映射（C++ 标准库 unordered_map 不保证顺序，这里用一个简单的 vector 维护顺序）
struct OrderedHashMap : public std::unordered_map<std::string, std::string> {
    std::vector<std::string> order;

    void put(const std::string& key, const std::string& value) {
        if (find(key) == end()) {
            order.push_back(key);
        }
        (*this)[key] = value;
    }

    friend std::ostream& operator<<(std::ostream& os, const OrderedHashMap& map) {
        os << "{";
        for (size_t i = 0; i < map.order.size(); ++i) {
            const auto& key = map.order[i];
            os << key << "=" << map.at(key);
            if (i != map.order.size() - 1) os << ", ";
        }
        os << "}";
        return os;
    }
};

// Listener 类
class PropertyFileLoader : public PropertyFileBaseListener {
public:
    OrderedHashMap props;

    void exitProp(PropertyFileParser::PropContext* ctx) override {
        std::string id = ctx->ID()->getText();
        std::string value = ctx->STRING()->getText();
        props.put(id, value);
    }
};

int main(int argc, char* argv[]) {
    std::string inputFile;
    if (argc > 1) {
        inputFile = argv[1];
    }

    std::unique_ptr<std::istream> inputStream;
    if (!inputFile.empty()) {
        inputStream = std::make_unique<std::ifstream>(inputFile);
        if (!*dynamic_cast<std::ifstream*>(inputStream.get())) {
            std::cerr << "Cannot open file: " << inputFile << std::endl;
            return 1;
        }
    } else {
        inputStream = std::make_unique<std::istream>(std::cin.rdbuf());
    }

    ANTLRInputStream input(*inputStream);
    PropertyFileLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    PropertyFileParser parser(&tokens);

    tree::ParseTree* tree = parser.file();

    ParseTreeWalker walker;
    PropertyFileLoader loader;
    walker.walk(&loader, tree);

    std::cout << loader.props << std::endl;

    return 0;
}
