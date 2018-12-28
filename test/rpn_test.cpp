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

TEST(rpn_test, func_charToOperator) {

    ASSERT_EQ(3, rpn::charToOperator('+')(1,2));
    ASSERT_EQ(4, rpn::charToOperator('-')(7,3));
    ASSERT_EQ(12, rpn::charToOperator('*')(4,3));
    ASSERT_EQ(4, rpn::charToOperator('/')(8, 2));
    // divide by zero return 0
    ASSERT_EQ(0, rpn::charToOperator('/')(3, 0));
    ASSERT_THROW(rpn::charToOperator('a'), invalid_argument);
}
