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

class Graph {
private:
    // 使用std::set保持节点唯一性和有序性
    std::set<std::string> nodes;
    // 使用std::multimap实现一对多映射
    std::multimap<std::string, std::string> edges;

public:
    void edge(const std::string& source, const std::string& target) {
        edges.insert({source, target});
        nodes.insert(source);
        nodes.insert(target);
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

    // 获取边对，用于模板生成
    std::vector<std::pair<std::string, std::string>> getPairs() const {
        std::vector<std::pair<std::string, std::string>> pairs;
        for (const auto& edge : edges) {
            pairs.push_back(edge);
        }
        return pairs;
    }

    const std::set<std::string>& getNodes() const {
        return nodes;
    }
};

// 简化版的StringTemplate替代方案
class SimpleTemplate {
public:
    static std::string render(const Graph& graph) {
        std::ostringstream buf;
        buf << "digraph G {\n";
        buf << "  ranksep=.25; \n";
        buf << "  edge [arrowsize=.5]\n";
        buf << "  node [shape=circle, fontname=\"ArialNarrow\",\n";
        buf << "        fontsize=12, fixedsize=true, height=.45];\n";
        
        // 输出所有函数节点
        for (const auto& node : graph.getNodes()) {
            buf << "  " << node << "; \n";
        }
        
        // 输出所有边
        auto pairs = graph.getPairs();
        for (const auto& pair : pairs) {
            buf << "  " << pair.first << " -> " << pair.second << ";\n";
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
        // 使用const_cast是因为graph需要修改，但Graph对象是可变的
        const_cast<Graph&>(graph).getNodes();
    }

    void exitCall(CymbolParser::CallContext* ctx) override {
        std::string funcName = ctx->ID()->getText();
        // 映射当前函数到被调用函数
        graph.edge(currentFunctionName, funcName);
    }

    Graph& getGraph() {
        return graph;
    }
};

int main(int argc, char* argv[]) {
    try {
        std::string inputFile;
        std::istream* is = &std::cin;
        std::ifstream fileStream;
        
        if (argc > 1) {
            inputFile = argv[1];
            fileStream.open(inputFile);
            if (!fileStream.is_open()) {
                std::cerr << "Cannot open file: " << inputFile << std::endl;
                return 1;
            }
            is = &fileStream;
        }
        
        // 创建ANTLR输入流
        ANTLRInputStream input(*is);
        CymbolLexer lexer(&input);
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
        
        // 使用模板生成输出
        // std::cout << SimpleTemplate::render(collector.getGraph()) << std::endl;
        
        if (fileStream.is_open()) {
            fileStream.close();
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}