#ifndef GRAPHICS_TEXTURE_HPP
#define GRAPHICS_TEXTURE_HPP

#include <common/global_defines.hpp>
#include <graphics/image.hpp>

namespace neutrino::graphics
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup graphics_renderer_module
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Texture.
///
/// Texture is a 2D Image. @n
/// It has 2 axis: S - is the horizontal axis and T - is the vertical axis.
/// Texture coordinates start at (0, 0) in the lower-left corner of the texture
/// and end at (1, 1) in the upper right corner
///
/// @see Shader, Mesh, Renderer
class Texture final
{
public:
    /// @brief The Texture minifying function
    enum class MinFilter
    {
        nearest, ///< Returns the value of the texture element that is nearest to the center of the pixel being textured.
        linear,  ///< Returns the weighted average of the four closest texture elements.

        nearest_mipmap_nearest, ///< Chooses the mipmap that most closely matches the size of the pixel being textured
                                ///< and uses the nearest criterion to produce a texture value.

        linear_mipmap_nearest, ///< Chooses the mipmap that most closely matches the size of the pixel being textured
                               ///< and uses the linear criterion to produce a texture value.

        nearest_mipmap_linear, ///< Chooses the two mipmaps that most closely match the size of the pixel being textured
                               ///< and uses the nearest criterion to produce a texture value from each mipmap.The final
                               ///< texture value is a weighted average of those two values.

        linear_mipmap_linear, ///< Chooses the two mipmaps that most closely match the size of the pixel being textured
                              ///< and uses the linear criterion to produce a texture value from each mipmap.The final
                              ///< texture value is a weighted average of those two values.
    };

    /// @brief The Texture magnification function
    enum class MagFilter
    {
        nearest, ///< Returns the value of the texture element that is nearest to the center of the pixel being textured.
        linear,  ///< Returns the weighted average of the four closest texture elements.
    };

    /// @brief The wrap parameter for texture coordinates.
    enum class Wrap
    {
        repeat,          ///< Creates a repeating pattern.
        mirrored_repeat, ///< As `repeat` but mirrors the image.
        clamp_to_edge,   ///< The out-of-bounds coordinates will be bound to the borders of the texture.
        clamp_to_border, ///< Coordinates outside the range will give the user-defined border color.
    };

    Texture() = default;
    LIBRARY_API Texture(const Texture& other);
    LIBRARY_API Texture(Texture&& other) noexcept;

    ~Texture() = default;

    LIBRARY_API Texture& operator=(const Texture& other);
    LIBRARY_API Texture& operator=(Texture&& other) noexcept;

    /// @brief Set image to Texture.
    ///
    /// @param image New texture image.
    LIBRARY_API void set_image(const Image& image);

    /// @brief Set image to Texture.
    ///
    /// @param image New texture image.
    LIBRARY_API void set_image(Image&& image);

    /// @brief Set the Texture wrap parameter for the S axis.
    ///
    /// @param wrap New parameter value.
    LIBRARY_API void set_wrap_s_parameter(Wrap wrap);

    /// @brief Set the Texture wrap parameter for the T axis.
    ///
    /// @param wrap New parameter value.
    LIBRARY_API void set_wrap_t_parameter(Wrap wrap);

    /// @brief Set the Texture border color.
    ///
    /// Used with Wrap::clamp_to_border. Default color is black (0x000000).
    ///
    /// @param color New border color.
    LIBRARY_API void set_border_color(const Color& color);

    /// @brief Set the Texture minifying filter.
    ///
    /// @param min_filter New minifying filter value.
    LIBRARY_API void set_min_filter(MinFilter min_filter);

    /// @brief Set the Texture magnification filter.
    ///
    /// @param mag_filter New magnification filter value.
    LIBRARY_API void set_mag_filter(MagFilter mag_filter);

    /// @brief Remove all sources from Texture.
    ///
    /// If Texture loaded to Renderer, it's can be freely cleaned.
    ///
    /// @see Renderer::load.
    LIBRARY_API void clear();

    /// @brief Get the texture image.
    ///
    /// @return Texture image.
    LIBRARY_API const Image& image() const;

    /// @brief Get the Texture wrap parameter for the S axis.
    ///
    /// @return The wrap parametr value.
    LIBRARY_API Wrap wrap_s_parameter() const;

    /// @brief Get the Texture wrap parameter for the T axis.
    ///
    /// @return The wrap parametr value.
    LIBRARY_API Wrap wrap_t_parameter() const;

    /// @brief Get the Texture border color.
    ///
    /// @return The texture border color.
    LIBRARY_API const Color& border_color() const;

    /// @brief Get the Texture minifying filter.
    ///
    /// @return The Texture minifying filter value.
    LIBRARY_API MinFilter min_filter() const;

    /// @brief Get the Texture magnification filter.
    ///
    /// @return The Texture magnification filter value.
    LIBRARY_API MagFilter mag_filter() const;

private:
    LIBRARY_API friend void swap(Texture& lhs, Texture& rhs) noexcept;

    Image m_image;

    Wrap m_wrap_s = Wrap::repeat;
    Wrap m_wrap_t = Wrap::repeat;

    Color m_border_color = Color(0x000000FFu);

    MinFilter m_min_filter = MinFilter::nearest_mipmap_linear;
    MagFilter m_mag_filter = MagFilter::linear;
};

/// @brief Swaps two Textures.
///
/// @param lhs Texture to swap.
/// @param rhs Texture to swap.
LIBRARY_API void swap(Texture& lhs, Texture& rhs) noexcept;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace neutrino::graphics

#endif
