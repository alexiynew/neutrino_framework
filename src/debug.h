#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>

#ifndef NDEBUG
#define NEED_ASSERT true
#endif

#ifdef FORCE_ASSERT
#define NEED_ASSERT true
#endif


#ifdef NEED_ASSERT

#define ASSERT(EXPR) ((EXPR) || (std::cout << __FILE__ << ":" << __LINE__ << " ASSERTION FAILED: " << (#EXPR) << std::endl, std::abort(), false))

#define ASSERT_MSG(EXPR, MSG) ((EXPR) || (std::cout << __FILE__ << ":" << __LINE__ << " ASSERTION FAILED: " << (MSG) << std::endl, std::abort(), false))

#else

#define ASSERT(EXPR) true

#define ASSERT_MSG(EXPR, MSG) true

#endif

#undef NEED_ASSERT

#endif
