#include "Token.hpp"

#include <sstream>
#include <vector>

#include "BacktrackLexer.hpp"

std::string Token::toString() const {
    std::string tname = BacktrackLexer::tokenNames[type];
    std::ostringstream oss;
    oss << "<'" << text << "'," << tname << ">";
    return oss.str();
}
