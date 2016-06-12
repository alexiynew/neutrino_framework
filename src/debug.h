#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <type_traits>

#include <iostream>
#include <cassert>

#ifndef NDEBUG
#define assert_msg(EXPR, MSG) \
    ((EXPR) || (std::cout << __FILE__ << ":" << __LINE__ << " ASSERTION FAILED: " << (MSG) << std::endl, abort(), false))

#else
#define assert_msg(PRED, MSG)

#endif

#endif
