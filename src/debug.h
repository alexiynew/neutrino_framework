#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <type_traits>

#include <cassert>
#include <iostream>

#ifndef NDEBUG
#define assert_msg(EXPR, MSG) \
    ((EXPR) || (std::cout << __FILE__ << ":" << __LINE__ << " ASSERTION FAILED: " << (MSG) << std::endl, std::abort(), false))

#else
#define assert_msg(PRED, MSG)

#endif

#endif
