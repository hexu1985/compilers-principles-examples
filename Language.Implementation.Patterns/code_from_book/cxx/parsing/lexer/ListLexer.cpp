#include "ListLexer.hpp"

// 静态成员定义（必须在类外）
const char* ListLexer::tokenNames[] = {
    "n/a",       // 索引 0
    "<EOF>",     // 索引 1
    "NAME",      // 索引 2
    "COMMA",     // 索引 3
    "LBRACK",    // 索引 4
    "RBRACK"     // 索引 5
};
