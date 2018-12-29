#include <gtest/gtest.h>

#include "src/rpn.cpp"

TEST(rpn_test, func_parse) {
    ASSERT_EQ(rpn::parse('/'), rpn::ParseResult::Operator);
    ASSERT_EQ(rpn::parse('*'), rpn::ParseResult::Operator);
    ASSERT_EQ(rpn::parse('+'), rpn::ParseResult::Operator);
    ASSERT_EQ(rpn::parse('-'), rpn::ParseResult::Operator);
    ASSERT_EQ(rpn::parse('0'), rpn::ParseResult::Operand);
    ASSERT_EQ(rpn::parse('3'), rpn::ParseResult::Operand);
    ASSERT_EQ(rpn::parse('9'), rpn::ParseResult::Operand);
    ASSERT_EQ(rpn::parse('a'), rpn::ParseResult::Invalid);
}

TEST(rpn_test, func_stringsToChars) {
    vector<char> result = {'h','e','l','l','o'};
    ASSERT_EQ(rpn::stringToChars("hello"), result);
}

TEST(rpn_test, func_charToInt) {
    ASSERT_EQ(rpn::charToInt('1'), 1);
    ASSERT_EQ(rpn::charToInt('9'), 9);
    ASSERT_THROW(rpn::charToInt('a'), invalid_argument);
}

TEST(rpn_test, func_charToOperator) {

    ASSERT_EQ(rpn::charToOperator('+')(1,2), 3);
    ASSERT_EQ(rpn::charToOperator('-')(7,3), 4);
    ASSERT_EQ(rpn::charToOperator('*')(4,3), 12);
    ASSERT_EQ(rpn::charToOperator('/')(8, 2), 4);
    // divide by zero return 0
    ASSERT_EQ(rpn::charToOperator('/')(3, 0), 0);
    ASSERT_THROW(rpn::charToOperator('a'), invalid_argument);
}

TEST(rpn_test, func_rpn) {
    ASSERT_EQ(rpn::rpn("1234+++"), 10);
    ASSERT_EQ(rpn::rpn("83+5-9+"), 15);
    ASSERT_EQ(rpn::rpn("893/*4+"), 28);
    ASSERT_THROW(rpn::rpn("8888+"), invalid_argument);
    ASSERT_THROW(rpn::rpn("88++88+"), invalid_argument);
    ASSERT_THROW(rpn::rpn("abcdefg"), invalid_argument);
}
