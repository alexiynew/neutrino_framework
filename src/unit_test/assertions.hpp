#ifndef FRAMEWORK_UNIT_TEST_ASSERTIONS_HPP
#define FRAMEWORK_UNIT_TEST_ASSERTIONS_HPP

// TODO: add description. id:4

#define TEST_FAIL(MSG) test_failed(__FILE__, __LINE__, (MSG) != 0 ? #MSG : "")

#define TEST_ASSERT(EXPRESSION, MSG) !(EXPRESSION) ? TEST_FAIL(MSG) : static_cast<void>(0)

#endif
