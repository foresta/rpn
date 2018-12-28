#include <gtest/gtest.h>

#include "src/rpn.cpp"

TEST(rpn_test, func_parse) {
    ASSERT_EQ(rpn::ParseResult::Operator, rpn::parse('/'));
    ASSERT_EQ(rpn::ParseResult::Operator, rpn::parse('*'));
    ASSERT_EQ(rpn::ParseResult::Operator, rpn::parse('+'));
    ASSERT_EQ(rpn::ParseResult::Operator, rpn::parse('-'));
    ASSERT_EQ(rpn::ParseResult::Operand, rpn::parse('0'));
    ASSERT_EQ(rpn::ParseResult::Operand, rpn::parse('3'));
    ASSERT_EQ(rpn::ParseResult::Operand, rpn::parse('9'));
    ASSERT_EQ(rpn::ParseResult::Invalid, rpn::parse('a'));
}

TEST(rpn_test, func_stringsToChars) {
    vector<char> result = {'h','e','l','l','o'};
    ASSERT_EQ(result, rpn::stringToChars("hello"));
}

TEST(rpn_test, func_charToInt) {
    ASSERT_EQ(1, rpn::charToInt('1'));
    ASSERT_EQ(9, rpn::charToInt('9'));
    ASSERT_THROW(rpn::charToInt('a'), invalid_argument);
}
