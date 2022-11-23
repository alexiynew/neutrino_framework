#ifndef COMMON_INC_UTILS_DETAILS_HPP
#define COMMON_INC_UTILS_DETAILS_HPP

#include <cstdint>
#include <istream>
#include <memory>

#include <random>

namespace neutrino::utils::details
{

#pragma region Random Numbers

template <typename T>
auto get_distribution(T min_value, T max_value)
{
    if constexpr (std::is_integral_v<T> == true) {
        return std::uniform_int_distribution<T>(min_value, max_value);
    } else {
        return std::uniform_real_distribution<T>(min_value, max_value);
    }
}

#pragma endregion

/*
namespace format_details
{
struct value_base
{
    virtual ~value_base()                         = default;
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

*/
} // namespace neutrino::utils::details

#endif
