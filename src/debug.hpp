#ifndef FRAMEWORK_DEBUG_HPP
#define FRAMEWORK_DEBUG_HPP

#include <iostream>

#ifndef NDEBUG
#define NEED_ASSERT true
#endif

#ifdef FORCE_ASSERT
#define NEED_ASSERT true
#endif

#ifdef NEED_ASSERT

#define ASSERT(EXPRESSION) \
    ((EXPRESSION) ||       \
     (std::cout << __FILE__ << ":" << __LINE__ << " ASSERTION FAILED: " << (#EXPRESSION) << std::endl, std::abort(), false))

#define ASSERT_MSG(EXPRESSION, MSG) \
    ((EXPRESSION) ||                \
     (std::cout << __FILE__ << ":" << __LINE__ << " ASSERTION FAILED: " << (MSG) << std::endl, std::abort(), false))

#else

#define ASSERT(EXPRESSION) true

#define ASSERT_MSG(EXPRESSION, MSG) true

#endif

#undef NEED_ASSERT

#endif
