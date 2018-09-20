/// @file
/// @brief CRC implementation.
/// @author Fedorov Alexey
/// @date 20.09.2018

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2018 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

#ifndef FRAMEWORK_COMMON_CRC_HPP
#define FRAMEWORK_COMMON_CRC_HPP

#include <common/types.hpp>
#include <common/crc_details.hpp>

namespace framework::utils
{
template <usize BitsCount>
class crc
{
public:
    using value_type = typename details::get_crc_value_type<BitsCount>::type;

    explicit crc(value_type poly, value_type init = 0, bool reflect_in = false, bool reflect_out = false, value_type xor_out = 0) noexcept;

    template <typename Iterator>
    value_type calculate(Iterator begin, Iterator end) const;
    
    value_type update(uint8 byte, value_type crc) const noexcept;

private:
    const value_type m_poly    = 0;
    const value_type m_init    = 0;
    const value_type m_xor_out = 0;
    const bool m_reflect_in    = false;
    const bool m_reflect_out   = false;
};

using crc8 = crc<8>;
using crc16 = crc<16>;
using crc32 = crc<32>;

#pragma region definitions

template <usize BitsCount>
inline crc<BitsCount>::crc(value_type poly, value_type init, bool reflect_in, bool reflect_out, value_type xor_out) noexcept
    : m_poly(poly), m_init(init), m_xor_out(xor_out), m_reflect_in(reflect_in), m_reflect_out(reflect_out)
{}

template <usize BitsCount>
template <typename Iterator>
inline typename crc<BitsCount>::value_type crc<BitsCount>::calculate(Iterator begin, Iterator end) const
{
    value_type out = m_init;

    for (;begin != end; ++begin) {
        out = update(m_reflect_in ? details::reflect(*begin) : *begin, out);
    }

    if (m_reflect_out) {
        out = details::reflect(out);
    }

    return (out ^ m_xor_out);
}

template <usize BitsCount>
inline typename crc<BitsCount>::value_type crc<BitsCount>::update(uint8 byte, value_type value) const noexcept
{
    constexpr int topbit = 1 << (BitsCount - 1);

    value = static_cast<value_type>(value ^ (byte << (BitsCount - 8)));
    for (uint8 bit = 8; bit > 0; --bit) {
        if (value & topbit) {
            value = static_cast<value_type>((value << 1) ^ m_poly);
        } else {
            value = static_cast<value_type>(value << 1);
        }
    }
    
    return value;
}

#pragma endregion

}

#endif
