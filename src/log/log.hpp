#ifndef FRAMEWORK_LOG_HPP
#define FRAMEWORK_LOG_HPP
// TODO realize logger interface
#include <iostream>

#ifndef NDEBUG
#define NEED_ASSERT true
#endif

#ifdef FORCE_ASSERT
#define NEED_ASSERT true
#endif

#ifdef NEED_ASSERT

#define ASSERT(EXPR) \
    ((EXPR) ||       \
     (std::cout << __FILE__ << ":" << __LINE__ << " ASSERTION FAILED: " << (#EXPR) << std::endl))

#define ASSERT_MSG(EXPR, MSG) \
    ((EXPR) ||                \
     (std::cout << __FILE__ << ":" << __LINE__ << " ASSERTION FAILED: " << (MSG) << std::endl))

#else

#define ASSERT(EXPR)

#define ASSERT_MSG(EXPR, MSG)

#endif

#undef NEED_ASSERT

#endif
