#ifndef FRAMEWORK_COMMON_VERSION_HPP
#define FRAMEWORK_COMMON_VERSION_HPP

#include <ostream>
#include <string>

#include <common/types.hpp>

namespace framework
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup utils_types_module
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Version implementation.
struct Version
{
public:
    /// @brief Creates Version instance.
    ///
    /// @param major_v Major version number.
    /// @param minor_v Minor version number.
    /// @param patch_v Patch version number.
    /// @param build_n Build version number.
    Version(int major_v, int minor_v, int patch_v = 0, int build_n = 0) noexcept;

    /// @brief Creates Version instance from string.
    ///
    /// @param version_string Version string in the dot-separated format (e.g. "1.2.3.4").
    explicit Version(const std::string& version_string);

    Version(const Version&) = default;
    Version(Version&&)      = default;

    ~Version() = default;

    Version& operator=(const Version&) = default;
    Version& operator=(Version&&) = default;

    /// @brief Version string.
    ///
    /// @return Version number as string e.g. "1.2.3.4".
    std::string as_string() const;

    /// @brief Major version number.
    ///
    /// @return Major version number.
    int major() const;

    /// @brief Minor version number.
    ///
    /// @return Minor version number.
    int minor() const;

    /// @brief Patch version number.
    ///
    /// @return Patch version number.
    int patch() const;

    /// @brief Build number.
    ///
    /// @return Build number.
    int build_number() const;

private:
    int m_major_version = 0;
    int m_minor_version = 0;
    int m_patch_version = 0;
    int m_build_number  = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Version operators
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Equality operator.
///
/// @param lhs version to compare.
/// @param rhs version to compare.
///
/// @return `true` if lhs equals rhs, otherwise `false`.
inline bool operator==(const Version& lhs, const Version& rhs) noexcept
{
    return lhs.major() == rhs.major() && lhs.minor() == rhs.minor() && lhs.patch() == rhs.patch() &&
           lhs.build_number() == rhs.build_number();
}

/// @brief Inequality operator.
///
/// @param lhs version to compare.
/// @param rhs version to compare.
///
/// @return `true` if lhs isn't equal rhs, otherwise `false`.
inline bool operator!=(const Version& lhs, const Version& rhs) noexcept
{
    return !(lhs == rhs);
}

/// @brief Less than operator.
///
/// @param lhs version to compare.
/// @param rhs version to compare.
///
/// @return `true` if lhs is less than rhs, otherwise `false`.
inline bool operator<(const Version& lhs, const Version& rhs) noexcept
{
    return (lhs.major() != rhs.major() ?
            lhs.major() < rhs.major() :
            (lhs.minor() != rhs.minor() ?
             lhs.minor() < rhs.minor() :
             (lhs.patch() != rhs.patch() ? lhs.patch() < rhs.patch() : lhs.build_number() < rhs.build_number())));
}

/// @brief Greater than operator.
///
/// @param lhs version to compare.
/// @param rhs version to compare.
///
/// @return `true` if lhs is greater than rhs, otherwise `false`.
inline bool operator>(const Version& lhs, const Version& rhs) noexcept
{
    return !(lhs < rhs) && lhs != rhs;
}

/// @brief Less than or equal operator.
///
/// @param lhs version to compare.
/// @param rhs version to compare.
///
/// @return `true` if lhs is less than or euqal rhs, otherwise `false`.
inline bool operator<=(const Version& lhs, const Version& rhs) noexcept
{
    return lhs < rhs || lhs == rhs;
}

/// @brief Greater than or equal operator.
///
/// @param lhs version to compare.
/// @param rhs version to compare.
///
/// @return `true` if lhs is greater than or equal rhs, otherwise `false`.
inline bool operator>=(const Version& lhs, const Version& rhs) noexcept
{
    return lhs > rhs || lhs == rhs;
}

/// @brief Insert Version to output stream.
///
/// @param os Output stream.
/// @param version Version to output.
inline std::ostream& operator<<(std::ostream& os, const Version& version)
{
    os << version.as_string();
    return os;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace framework

#endif
