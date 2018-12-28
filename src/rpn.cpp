#include "rpn.h"
#include <vector>

using namespace std;

namespace rpn {

    // パース結果
    enum class ParseResult {
        Operator = 0,
        Operand,
        Invalid
    };

    ParseResult parse(const char& c) {
        if (isdigit(static_cast<unsigned char>(c))) {
            return ParseResult::Operand;
        }

        if (c == '+' || c == '-' || c == '*' || c == '/') {
            return ParseResult::Operator;
        }

        return ParseResult::Invalid;
    }

    vector<char> stringToChars(const string& s) {
        vector<char> result(s.begin(), s.end());
        return result;
    }

    int charToInt(const char& c) {
        if (!isdigit(static_cast<unsigned char>(c))) {
            throw invalid_argument("argument should be number character");
        }
        return c - '0';
    }

}
