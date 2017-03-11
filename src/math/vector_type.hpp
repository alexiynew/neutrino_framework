#ifndef FRAMEWORK_MATH_VECTOR_TYPE_HPP
#define FRAMEWORK_MATH_VECTOR_TYPE_HPP

#include <log/log.hpp>
#include <math/common_func.hpp>
#include <math/utils.hpp>

namespace framework {

namespace math {

namespace vector_impl {

template <typename T>
struct is_arithmetic_and_not_bool
{
    static constexpr bool value = std::is_arithmetic<T>::value and not std::is_same<T, bool>::value;
};

template <typename T>
struct create_value_of_type
{
    template <typename U>
    inline static constexpr T from(const U& value)
    {
        return static_cast<T>(value);
    }
};

template <>
struct create_value_of_type<bool>
{
    template <typename U>
    inline static constexpr bool from(const U& value)
    {
        return ::framework::math::abs(value) > 0;
    }
};

template <unsigned int N, typename T>
struct vector_base
{
};

template <typename T>
struct vector_base<4, T>
{
    template <typename T1, typename T2, typename T3, typename T4>
    constexpr vector_base(T1 xx, T2 yy, T3 zz, T4 ww) noexcept : x{create_value_of_type<T>::from(xx)},
                                                                 y{create_value_of_type<T>::from(yy)},
                                                                 z{create_value_of_type<T>::from(zz)},
                                                                 w{create_value_of_type<T>::from(ww)}
    {
    }

    T x, y, z, w;
};

template <typename T>
struct vector_base<3, T>
{
    template <typename T1, typename T2, typename T3>
    constexpr vector_base(T1 xx, T2 yy, T3 zz) noexcept : x{create_value_of_type<T>::from(xx)},
                                                          y{create_value_of_type<T>::from(yy)},
                                                          z{create_value_of_type<T>::from(zz)}
    {
    }

    T x, y, z;
};

template <typename T>
struct vector_base<2, T>
{
    template <typename T1, typename T2>
    constexpr vector_base(T1 xx, T2 yy) noexcept : x{create_value_of_type<T>::from(xx)},
                                                   y{create_value_of_type<T>::from(yy)}
    {
    }

    T x, y;
};



#pragma mark - Vector template declaration

template <unsigned int N, typename T>
struct Vector;

#pragma mark - Vector<4, T> type specialization

template <typename T>
struct Vector<4, T> final : public vector_base<4, T>
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");
    using ValueType = T;
    using base_type = vector_base<4, T>;

    constexpr Vector();

    constexpr Vector(const Vector<4, ValueType>&) = default;
    constexpr Vector(Vector<4, ValueType>&&)      = default;

    constexpr Vector(const ValueType& xx, const ValueType& yy, const ValueType& zz, const ValueType& ww);
    explicit constexpr Vector(const ValueType& v);

    template <typename U>
    explicit constexpr Vector(const U* const p);

    template <typename U>
    explicit constexpr Vector(const Vector<4, U>& v);

    template <typename U>
    explicit constexpr Vector(const Vector<3, U>& v);

    template <typename U, typename S>
    constexpr Vector(const S& s, const Vector<3, U>& v);

    template <typename U, typename S>
    constexpr Vector(const Vector<3, U>& v, const S& s);

    template <typename U>
    explicit constexpr Vector(const Vector<2, U>& v);

    template <typename U1, typename U2>
    constexpr Vector(const Vector<2, U1>& v1, const Vector<2, U2>& v2);

    template <typename U, typename S1, typename S2>
    constexpr Vector(const S1& xx, const S2& yy, const Vector<2, U>& v);

    template <typename U, typename S1, typename S2>
    constexpr Vector(const S1& xx, const Vector<2, U>& v, const S2& ww);

    template <typename U, typename S1, typename S2>
    constexpr Vector(const Vector<2, U>& v, const S1& zz, const S2& ww);

    Vector<4, ValueType>& operator=(const Vector<4, ValueType>&) = default;
    Vector<4, ValueType>& operator=(Vector<4, ValueType>&&) = default;

    template <typename U>
    Vector<4, ValueType>& operator=(const Vector<4, U>& other);

    ValueType& operator[](unsigned int index);
    const ValueType& operator[](unsigned int index) const;

    constexpr unsigned int size() const;

    ValueType* data();
    const ValueType* data() const;
};


#pragma mark - Vector<3, T> type specialization

template <typename T>
struct Vector<3, T> final : public vector_base<3, T>
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");
    using ValueType = T;
    using base_type = vector_base<3, T>;

    constexpr Vector();

    constexpr Vector(const Vector<3, ValueType>&) = default;
    constexpr Vector(Vector<3, ValueType>&&)      = default;

    constexpr Vector(const ValueType& xx, const ValueType& yy, const ValueType& zz);

    explicit constexpr Vector(const ValueType& v);

    template <typename U>
    explicit constexpr Vector(const U* const p);

    template <typename U>
    explicit constexpr Vector(const Vector<4, U>& v);

    template <typename U>
    explicit constexpr Vector(const Vector<3, U>& v);

    template <typename U>
    explicit constexpr Vector(const Vector<2, U>& v);

    template <typename U, typename S>
    constexpr Vector(const S& xx, const Vector<2, U>& v);

    template <typename U, typename S>
    constexpr Vector(const Vector<2, U>& v, const S& zz);

    Vector<3, ValueType>& operator=(const Vector<3, ValueType>&) = default;
    Vector<3, ValueType>& operator=(Vector<3, ValueType>&&) = default;

    template <typename U>
    Vector<3, ValueType>& operator=(const Vector<3, U>& other);

    ValueType& operator[](unsigned int index);
    const ValueType& operator[](unsigned int index) const;

    constexpr unsigned int size() const;

    ValueType* data();
    const ValueType* data() const;
};

#pragma mark - Vector<2, T> type specialization

template <typename T>
struct Vector<2, T> final : public vector_base<2, T>
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");
    using ValueType = T;
    using base_type = vector_base<2, T>;

    constexpr Vector();

    constexpr Vector(const Vector<2, ValueType>&) = default;
    constexpr Vector(Vector<2, ValueType>&&)      = default;

    constexpr Vector(const ValueType& xx, const ValueType& yy);

    explicit constexpr Vector(const ValueType& v);

    template <typename U>
    explicit constexpr Vector(const U* p);

    template <typename U>
    explicit constexpr Vector(const Vector<4, U>& v);

    template <typename U>
    explicit constexpr Vector(const Vector<3, U>& v);

    template <typename U>
    explicit constexpr Vector(const Vector<2, U>& v);

    Vector<2, ValueType>& operator=(const Vector<2, ValueType>&) = default;
    Vector<2, ValueType>& operator=(Vector<2, ValueType>&&) = default;

    template <typename U>
    Vector<2, ValueType>& operator=(const Vector<2, U>& other);

    ValueType& operator[](unsigned int index);
    const ValueType& operator[](unsigned int index) const;

    constexpr unsigned int size() const;

    ValueType* data();
    const ValueType* data() const;
};

#pragma mark - Vector<4, T> implementation

// constructors
template <typename T>
inline constexpr Vector<4, T>::Vector()
    : base_type{0, 0, 0, static_cast<T>(not std::is_same<T, bool>::value)}
{
}

template <typename T>
inline constexpr Vector<4, T>::Vector(const T& xx, const T& yy, const T& zz, const T& ww)
    : base_type{xx, yy, zz, ww}
{
}

template <typename T>
inline constexpr Vector<4, T>::Vector(const T& v)
    : base_type{v, v, v, v}
{
}

template <typename T>
template <typename U>
inline constexpr Vector<4, T>::Vector(const U* const p)
    : base_type{*p, *(p + 1), *(p + 2), *(p + 3)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}


template <typename T>
template <typename U>
inline constexpr Vector<4, T>::Vector(const Vector<4, U>& v)
    : base_type{v.x, v.y, v.z, v.w}
{
}

template <typename T>
template <typename U>
inline constexpr Vector<4, T>::Vector(const Vector<3, U>& v)
    : base_type{v.x, v.y, v.z, static_cast<T>(not std::is_same<T, bool>::value)}
// TODO add test for this
{
}

template <typename T>
template <typename U, typename S>
inline constexpr Vector<4, T>::Vector(const S& s, const Vector<3, U>& v)
    : base_type{s, v.x, v.y, v.z}
{
}

template <typename T>
template <typename U, typename S>
inline constexpr Vector<4, T>::Vector(const Vector<3, U>& v, const S& s)
    : base_type{v.x, v.y, v.z, s}
{
}

template <typename T>
template <typename U>
inline constexpr Vector<4, T>::Vector(const Vector<2, U>& v)
    : base_type{v.x, v.y, T(0), static_cast<T>(not std::is_same<T, bool>::value)}
// TODO add test for this
{
}

template <typename T>
template <typename U1, typename U2>
inline constexpr Vector<4, T>::Vector(const Vector<2, U1>& v1, const Vector<2, U2>& v2)
    : base_type{v1.x, v1.y, v2.x, v2.y}
{
}

template <typename T>
template <typename U, typename S1, typename S2>
inline constexpr Vector<4, T>::Vector(const S1& xx, const S2& yy, const Vector<2, U>& v)
    : base_type{xx, yy, v.x, v.y}
{
}

template <typename T>
template <typename U, typename S1, typename S2>
inline constexpr Vector<4, T>::Vector(const S1& xx, const Vector<2, U>& v, const S2& ww)
    : base_type{xx, v.x, v.y, ww}
{
}

template <typename T>
template <typename U, typename S1, typename S2>
inline constexpr Vector<4, T>::Vector(const Vector<2, U>& v, const S1& zz, const S2& ww)
    : base_type{v.x, v.y, zz, ww}
{
}

// operators
template <typename T>
template <typename U>
inline Vector<4, T>& Vector<4, T>::operator=(const Vector<4, U>& other)
{
    base_type::x = create_value_of_type<T>::from(other.x);
    base_type::y = create_value_of_type<T>::from(other.y);
    base_type::z = create_value_of_type<T>::from(other.z);
    base_type::w = create_value_of_type<T>::from(other.w);

    return *this;
}

// access operator
template <typename T>
inline typename Vector<4, T>::ValueType& Vector<4, T>::operator[](unsigned int index)
{
    ASSERT_MSG(index >= 0 && index < 4, "Wrong index.");
    return data()[index];
}

template <typename T>
inline const typename Vector<4, T>::ValueType& Vector<4, T>::operator[](unsigned int index) const
{
    ASSERT_MSG(index >= 0 && index < 4, "Wrong index.");
    return data()[index];
}

// methods
template <typename T>
inline constexpr unsigned int Vector<4, T>::size() const
{
    return 4;
}

template <typename T>
inline typename Vector<4, T>::ValueType* Vector<4, T>::data()
{
    return &(this->x);
}

template <typename T>
inline const typename Vector<4, T>::ValueType* Vector<4, T>::data() const
{
    return &(this->x);
}

#pragma mark - Vector<3, T> implementation

// constructors
template <typename T>
inline constexpr Vector<3, T>::Vector()
    : base_type{0, 0, 0}
{
}

template <typename T>
inline constexpr Vector<3, T>::Vector(const T& xx, const T& yy, const T& zz)
    : base_type{xx, yy, zz}
{
}

template <typename T>
inline constexpr Vector<3, T>::Vector(const T& v)
    : base_type{v, v, v}
{
}

template <typename T>
template <typename U>
inline constexpr Vector<3, T>::Vector(const U* const p)
    : base_type{*p, *(p + 1), *(p + 2)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline constexpr Vector<3, T>::Vector(const Vector<4, U>& v)
    : base_type{v.x, v.y, v.z}
{
}

template <typename T>
template <typename U>
inline constexpr Vector<3, T>::Vector(const Vector<3, U>& v)
    : base_type{v.x, v.y, v.z}
{
}

template <typename T>
template <typename U>
inline constexpr Vector<3, T>::Vector(const Vector<2, U>& v)
    : base_type{v.x, v.y, T(0)}
{
}

template <typename T>
template <typename U, typename S>
inline constexpr Vector<3, T>::Vector(const S& xx, const Vector<2, U>& v)
    : base_type{xx, v.x, v.y}
{
}

template <typename T>
template <typename U, typename S>
inline constexpr Vector<3, T>::Vector(const Vector<2, U>& v, const S& zz)
    : base_type{v.x, v.y, zz}
{
}

// operators
template <typename T>
template <typename U>
inline Vector<3, T>& Vector<3, T>::operator=(const Vector<3, U>& other)
{
    base_type::x = create_value_of_type<T>::from(other.x);
    base_type::y = create_value_of_type<T>::from(other.y);
    base_type::z = create_value_of_type<T>::from(other.z);

    return *this;
}

// access operator
template <typename T>
inline typename Vector<3, T>::ValueType& Vector<3, T>::operator[](unsigned int index)
{
    ASSERT_MSG(index >= 0 && index < 3, "Wrong index.");
    return data()[index];
}

template <typename T>
inline const typename Vector<3, T>::ValueType& Vector<3, T>::operator[](unsigned int index) const
{
    ASSERT_MSG(index >= 0 && index < 3, "Wrong index.");
    return data()[index];
}

// methods
template <typename T>
inline constexpr unsigned int Vector<3, T>::size() const
{
    return 3;
}

template <typename T>
inline typename Vector<3, T>::ValueType* Vector<3, T>::data()
{
    return &(this->x);
}

template <typename T>
inline const typename Vector<3, T>::ValueType* Vector<3, T>::data() const
{
    return &(this->x);
}

#pragma mark - Vector<2, T> implementation

// constructors
template <typename T>
inline constexpr Vector<2, T>::Vector()

    : base_type{0, 0}
{
}

template <typename T>
inline constexpr Vector<2, T>::Vector(const T& xx, const T& yy)
    : base_type{xx, yy}
{
}

template <typename T>
inline constexpr Vector<2, T>::Vector(const T& v)
    : base_type{v, v}
{
}

template <typename T>
template <typename U>
inline constexpr Vector<2, T>::Vector(const U* p)
    : base_type{*p, *(p + 1)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline constexpr Vector<2, T>::Vector(const Vector<4, U>& v)
    : base_type{v.x, v.y}
{
}

template <typename T>
template <typename U>
inline constexpr Vector<2, T>::Vector(const Vector<3, U>& v)
    : base_type{v.x, v.y}
{
}
template <typename T>
template <typename U>
inline constexpr Vector<2, T>::Vector(const Vector<2, U>& v)
    : base_type{v.x, v.y}
{
}

// operators
template <typename T>
template <typename U>
inline Vector<2, T>& Vector<2, T>::operator=(const Vector<2, U>& other)
{
    base_type::x = create_value_of_type<T>::from(other.x);
    base_type::y = create_value_of_type<T>::from(other.y);

    return *this;
}

// access operator
template <typename T>
inline typename Vector<2, T>::ValueType& Vector<2, T>::operator[](unsigned int index)
{
    ASSERT_MSG(index >= 0 && index < 2, "Wrong index.");
    return data()[index];
}

template <typename T>
inline const typename Vector<2, T>::ValueType& Vector<2, T>::operator[](unsigned int index) const
{
    ASSERT_MSG(index >= 0 && index < 2, "Wrong index.");
    return data()[index];
}

// methods
template <typename T>
inline constexpr unsigned int Vector<2, T>::size() const
{
    return 2;
}

template <typename T>
inline typename Vector<2, T>::ValueType* Vector<2, T>::data()
{
    return &(this->x);
}

template <typename T>
inline const typename Vector<2, T>::ValueType* Vector<2, T>::data() const
{
    return &(this->x);
}


#pragma mark - unary operators

template <unsigned int N, typename T>
inline Vector<N, T> operator-(Vector<N, T> vector)
{
    return vector *= -T(1);
}

template <unsigned int N, typename T>
inline Vector<N, T> operator+(const Vector<N, T>& vector)
{
    return vector;
}


template <unsigned int N, typename T, typename U>
inline Vector<N, T>& operator+=(Vector<N, T>& lhs, const Vector<N, U>& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] += create_value_of_type<T>::from(rhs[i]);
    }

    return lhs;
}

template <unsigned int N, typename T, typename U>
inline Vector<N, T>& operator-=(Vector<N, T>& lhs, const Vector<N, U>& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] -= create_value_of_type<T>::from(rhs[i]);
    }

    return lhs;
}


template <unsigned int N, typename T, typename U>
inline Vector<N, T>& operator*=(Vector<N, T>& lhs, const Vector<N, U>& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] *= create_value_of_type<T>::from(rhs[i]);
    }

    return lhs;
}

template <unsigned int N, typename T, typename U>
inline Vector<N, T>& operator/=(Vector<N, T>& lhs, const Vector<N, U>& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] /= create_value_of_type<T>::from(rhs[i]);
    }

    return lhs;
}


template <unsigned int N, typename T, typename U>
inline Vector<N, T>& operator+=(Vector<N, T>& lhs, const U& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] += create_value_of_type<T>::from(rhs);
    }

    return lhs;
}

template <unsigned int N, typename T, typename U>
inline Vector<N, T>& operator-=(Vector<N, T>& lhs, const U& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] -= create_value_of_type<T>::from(rhs);
    }

    return lhs;
}

template <unsigned int N, typename T, typename U>
inline Vector<N, T>& operator*=(Vector<N, T>& lhs, const U& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] *= create_value_of_type<T>::from(rhs);
    }

    return lhs;
}

template <unsigned int N, typename T, typename U>
inline Vector<N, T>& operator/=(Vector<N, T>& lhs, const U& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] /= create_value_of_type<T>::from(rhs);
    }

    return lhs;
}

#pragma mark - binary operators: vector - vector

template <unsigned int N, typename T>
inline const Vector<N, T> operator+(Vector<N, T> lhs, const Vector<N, T>& rhs)
{
    return lhs += rhs;
}

template <unsigned int N, typename T>
inline const Vector<N, T> operator-(Vector<N, T> lhs, const Vector<N, T>& rhs)
{
    return lhs -= rhs;
}

template <unsigned int N, typename T>
inline const Vector<N, T> operator*(Vector<N, T> lhs, const Vector<N, T>& rhs)
{
    return lhs *= rhs;
}

template <unsigned int N, typename T>
inline const Vector<N, T> operator/(Vector<N, T> lhs, const Vector<N, T>& rhs)
{
    return lhs /= rhs;
}

#pragma mark - binary operators: vector - scalar

template <unsigned int N, typename T>
inline const Vector<N, T> operator+(Vector<N, T> vector, const T& scalar)
{
    return vector += scalar;
}

template <unsigned int N, typename T>
inline const Vector<N, T> operator-(Vector<N, T> vector, const T& scalar)
{
    return vector -= scalar;
}

template <unsigned int N, typename T>
inline const Vector<N, T> operator*(Vector<N, T> vector, const T& scalar)
{
    return vector *= scalar;
}

template <unsigned int N, typename T>
inline const Vector<N, T> operator/(Vector<N, T> vector, const T& scalar)
{
    return vector /= scalar;
}

#pragma mark - binary operators: scalar - vector

template <unsigned int N, typename T>
inline const Vector<N, T> operator+(const T& scalar, const Vector<N, T>& vector)
{
    Vector<N, T> tmp{scalar};
    return tmp += vector;
}

template <unsigned int N, typename T>
inline const Vector<N, T> operator-(const T& scalar, const Vector<N, T>& vector)
{
    Vector<N, T> tmp{scalar};
    return tmp -= vector;
}

template <unsigned int N, typename T>
inline const Vector<N, T> operator*(const T& scalar, const Vector<N, T>& vector)
{
    Vector<N, T> tmp{scalar};
    return tmp *= vector;
}

template <unsigned int N, typename T>
inline const Vector<N, T> operator/(const T& scalar, const Vector<N, T>& vector)
{
    Vector<N, T> tmp{scalar};
    return tmp /= vector;
}

#pragma mark - vectors equality

template <typename T>
inline constexpr bool operator==(const Vector<4, T>& a, const Vector<4, T>& b)
{
    const auto& abs = ::framework::math::abs<T>;
    return abs(a.x - b.x) <= 0 && abs(a.y - b.y) <= 0 && abs(a.z - b.z) <= 0 && abs(a.w - b.w) <= 0;
}

template <typename T>
inline constexpr bool operator==(const Vector<3, T>& a, const Vector<3, T>& b)
{
    const auto& abs = ::framework::math::abs<T>;
    return abs(a.x - b.x) <= 0 && abs(a.y - b.y) <= 0 && abs(a.z - b.z) <= 0;
}

template <typename T>
inline constexpr bool operator==(const Vector<2, T>& a, const Vector<2, T>& b)
{
    const auto& abs = ::framework::math::abs<T>;
    return abs(a.x - b.x) <= 0 && abs(a.y - b.y) <= 0;
}

template <typename T>
inline constexpr bool operator!=(const Vector<4, T>& a, const Vector<4, T>& b)
{
    const auto& abs = ::framework::math::abs<T>;
    return abs(a.x - b.x) > 0 && abs(a.y - b.y) > 0 && abs(a.z - b.z) > 0 && abs(a.w - b.w) > 0;
}

template <typename T>
inline constexpr bool operator!=(const Vector<3, T>& a, const Vector<3, T>& b)
{
    const auto& abs = ::framework::math::abs<T>;
    return abs(a.x - b.x) > 0 && abs(a.y - b.y) > 0 && abs(a.z - b.z) > 0;
}

template <typename T>
inline constexpr bool operator!=(const Vector<2, T>& a, const Vector<2, T>& b)
{
    const auto& abs = ::framework::math::abs<T>;
    return abs(a.x - b.x) > 0 && abs(a.y - b.y);
}

} // namespace vector_impl

} // namespace math

} // namespace framework

#endif
