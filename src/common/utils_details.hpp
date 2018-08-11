/// @file
/// @brief Implementation details of utils functions
/// @author Fedorov Alexey
/// @date 11.07.2018

#ifndef FRAMEWORK_COMMON_UTILS_DETAILS_HPP
#define FRAMEWORK_COMMON_UTILS_DETAILS_HPP

#include <iostream>
#include <memory>

namespace framework
{
namespace utils
{
namespace format_details
{
struct value_base
{
    virtual ~value_base(){};
    virtual void print_to(std::ostream& os) const = 0;
};

template <typename T>
struct value_holder : public value_base
{
    value_holder(const T& v) : value(v)
    {}
    void print_to(std::ostream& os) const override
    {
        os << value;
    }
    const T& value;
};

template <typename T>
inline std::unique_ptr<value_base> make_value_holder_ptr(const T& t)
{
    return std::unique_ptr<value_base>(new value_holder<T>(t));
}

std::string make_string_impl(const std::string& str,
                             const std::unique_ptr<value_base>* const values,
                             const size_t values_count);

} // namespace format_details

} // namespace utils

} // namespace framework

#endif
