#include "Token.hpp"

#include <sstream>
#include <vector>

#include "ListLexer.hpp"

std::string Token::toString() const {
    std::string tname = ListLexer::tokenNames[type];
    std::ostringstream oss;
    oss << "<'" << text << "'," << tname << ">";
    return oss.str();
}
