#include "rpn.h"
#include <vector>
#include <stack>
#include <functional>

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

    function<int(int, int)> charToOperator(const char& c) {
        switch (c) {
            case '+':
                return [](int a, int b){ return a + b; };
            case '-':
                return [](int a, int b){ return a - b; };
            case '*':
                return [](int a, int b){ return a * b; };
            case '/':
                return [](int a, int b){ if (b == 0) return 0; return a/ b; };
            default:
                throw invalid_argument("operator should be +-*/");
        }
    }


    int rpn(const string& s) {
        stack<int> operands;

        for (const char c : stringToChars(s)) {
            ParseResult parseResult = parse(c);
            switch (parseResult) {
                case ParseResult::Operator:
                    {
                        if (operands.size() < 2) {
                            throw invalid_argument("Invalid RPN syntax.(operator should be required two operands)");
                        }

                        auto op2 = operands.top();
                        operands.pop();

                        auto op1 = operands.top();
                        operands.pop();

                        int result = charToOperator(c)(op1, op2);
                        operands.push(result);

                        break;
                    }
                case ParseResult::Operand:
                    {
                        operands.push(charToInt(c));
                        break;
                    }
                case ParseResult::Invalid:
                    {
                        throw invalid_argument("Invalid character exists.");
                    }
            }
        }

        if (operands.size() != 1) {
            throw invalid_argument("Invalid RPN syntax.(RPN result is one operand)");
        }

        return operands.top();
    }
}
