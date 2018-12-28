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
