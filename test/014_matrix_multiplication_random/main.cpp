#include <iomanip>
#include <iostream>
#include <math/fmath.h>
#include <sstream>
#include <string>

using namespace framework::math;

namespace {

template <U32 N, typename T, template <U32, typename> class TVec>
std::string to_string_impl(const TVec<N, T>& v)
{
    std::stringstream ss;
    ss.precision(14);
    ss << "[";
    for (U32 i = 0; i < N; ++i) {
        ss << v[i] << (i < N - 1 ? ", " : "");
    }
    ss << "]";
    return ss.str();
}

template <U32 C, U32 R, typename T, template <U32, U32, typename> class TMat>
std::string to_string_impl(const TMat<C, R, T>& m)
{
    std::stringstream ss;
    ss.precision(14);
    ss << "[";
    for (U32 i = 0; i < R; ++i) {
        for (U32 j = 0; j < C; ++j) {
            ss << m.row(i)[j] << (j < C - 1 ? ", " : "");
        }
        ss << (i < R - 1 ? "; " : "");
    }
    ss << "]";
    return ss.str();
}

struct Any;

template <typename T>
struct TAny;

template <typename T>
Any* make_any(const T& v)
{
    return new TAny<T>(v);
}

template <typename T, typename U>
Any* multiply_impl(const T&, const U&)
{
    throw "Wrong parameters";
    return nullptr;
}

template <U32 R, U32 C>
Any* multiply_impl(const Vector<R, F32>& lhs, const Matrix<C, R, F32>& rhs)
{
    return make_any(lhs * rhs);
}

template <U32 R, U32 C>
Any* multiply_impl(const Matrix<C, R, F32>& lhs, const Vector<C, F32>& rhs)
{
    return make_any(lhs * rhs);
}

template <U32 C, U32 R, U32 K>
Any* multiply_impl(const Matrix<C, R, F32>& lhs, const Matrix<K, C, F32>& rhs)
{
    return make_any(lhs * rhs);
}

struct Any
{
    virtual std::string to_string() = 0;

    virtual Any* multiply(Any* other) = 0;

    virtual Any* multiply(const Vector<2, F32>& v) = 0;
    virtual Any* multiply(const Vector<3, F32>& v) = 0;
    virtual Any* multiply(const Vector<4, F32>& v) = 0;

    virtual Any* multiply(const Matrix<2, 2, F32>& m) = 0;
    virtual Any* multiply(const Matrix<2, 3, F32>& m) = 0;
    virtual Any* multiply(const Matrix<2, 4, F32>& m) = 0;

    virtual Any* multiply(const Matrix<3, 2, F32>& m) = 0;
    virtual Any* multiply(const Matrix<3, 3, F32>& m) = 0;
    virtual Any* multiply(const Matrix<3, 4, F32>& m) = 0;

    virtual Any* multiply(const Matrix<4, 2, F32>& m) = 0;
    virtual Any* multiply(const Matrix<4, 3, F32>& m) = 0;
    virtual Any* multiply(const Matrix<4, 4, F32>& m) = 0;

    virtual ~Any()
    {
    }
};

template <typename T>
struct TAny : public Any
{
    explicit TAny(const T& v)
        : value(v)
    {
    }
    T value;

    std::string to_string() override
    {
        return to_string_impl(value);
    }

    Any* multiply(Any* other) override
    {
        return other->multiply(value);
    }

    Any* multiply(const Vector<2, F32>& v) override
    {
        return multiply_impl(v, value);
    }

    Any* multiply(const Vector<3, F32>& v) override
    {
        return multiply_impl(v, value);
    }

    Any* multiply(const Vector<4, F32>& v) override
    {
        return multiply_impl(v, value);
    }

    Any* multiply(const Matrix<2, 2, F32>& m) override
    {
        return multiply_impl(m, value);
    }

    Any* multiply(const Matrix<2, 3, F32>& m) override
    {
        return multiply_impl(m, value);
    }

    Any* multiply(const Matrix<2, 4, F32>& m) override
    {
        return multiply_impl(m, value);
    }

    Any* multiply(const Matrix<3, 2, F32>& m) override
    {
        return multiply_impl(m, value);
    }

    Any* multiply(const Matrix<3, 3, F32>& m) override
    {
        return multiply_impl(m, value);
    }

    Any* multiply(const Matrix<3, 4, F32>& m) override
    {
        return multiply_impl(m, value);
    }

    Any* multiply(const Matrix<4, 2, F32>& m) override
    {
        return multiply_impl(m, value);
    }

    Any* multiply(const Matrix<4, 3, F32>& m) override
    {
        return multiply_impl(m, value);
    }

    Any* multiply(const Matrix<4, 4, F32>& m) override
    {
        return multiply_impl(m, value);
    }
};

template <U32 N>
Vector<N, F32> readVector()
{
    Vector<N, F32> value;
    for (U32 i = 0; i < N; ++i) {
        std::cin >> value[i];
    }
    return value;
}

template <U32 C, U32 R>
Any* readVectorImpl()
{
    Matrix<R, C, F32> m;
    for (U32 i = 0; i < R; ++i) {
        m[i] = readVector<C>();
    }
    return new TAny<Matrix<C, R, F32>>(transpose(m));
}

template <U32 R>
Any* read(int col)
{
    switch (col) {
        case 1: return new TAny<Vector<R, F32>>(readVector<R>());
        case 2: return readVectorImpl<2, R>();
        case 3: return readVectorImpl<3, R>();
        case 4: return readVectorImpl<4, R>();
        default: throw "Zero cols";
    }
}

Any* read()
{
    int row = 0, col = 0;
    std::cin >> row >> col;

    switch (row) {
        case 1: {
            switch (col) {
                case 2: return new TAny<Vector<2, F32>>(readVector<2>());
                case 3: return new TAny<Vector<3, F32>>(readVector<3>());
                case 4: return new TAny<Vector<4, F32>>(readVector<4>());
                default: throw "Zero cols";
            }
        }
        case 2: return read<2>(col);
        case 3: return read<3>(col);
        case 4: return read<4>(col);
        default: throw "Zero rows";
    }
}
}

int main()
{
    std::cout.precision(20);
    while (std::cin) {

        Any* a = read();
        Any* b = read();

        // std::cout << a->to_string() << std::endl;
        // std::cout << b->to_string() << std::endl;

        Any* res = a->multiply(b);
        std::cout << res->to_string() << std::endl;

        delete a;
        delete b;
        delete res;

        std::cin.peek();
    }

    return 0;
}
