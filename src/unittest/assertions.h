#ifndef FRAMEWORK_UNITTEST_ASSERTIONS_H
#define FRAMEWORK_UNITTEST_ASSERTIONS_H

// TODO: add description. id:4

#define TEST_FAIL(MSG) test_failed(__FILE__, __LINE__, (MSG) != 0 ? #MSG : "")

#define TEST_ASSERT(EXPR, MSG) !(EXPR) ? TEST_FAIL(MSG) : static_cast<void>(0)

#endif
