#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <type_traits>

#include <iostream>

#ifndef NDEBUG
#define NEED_ASSERT true
#endif

#ifdef FORCE_ASSERT
#define NEED_ASSERT true
#endif


#ifdef NEED_ASSERT

#define assert(EXPR) \
    ((EXPR) || (std::abort(), false))

#define assert_msg(EXPR, MSG) \
    ((EXPR) || (std::cout << __FILE__ << ":" << __LINE__ << " ASSERTION FAILED: " << (MSG) << std::endl, std::abort(), false))

#else

#define assert(EXPR) true

#define assert_msg(EXPR, MSG) true

#endif

#undef NEED_ASSERT

#endif
