#include "Token.hpp"

#include <sstream>
#include <vector>

#include "LookaheadLexer.hpp"

std::string Token::toString() const {
    std::string tname = LookaheadLexer::tokenNames[type];
    std::ostringstream oss;
    oss << "<'" << text << "'," << tname << ">";
    return oss.str();
}
