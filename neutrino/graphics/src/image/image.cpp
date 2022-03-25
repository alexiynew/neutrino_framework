#include <common/exceptions.hpp>
#include <graphics/image.hpp>
#include <log/log.hpp>

#include <graphics/src/image/bmp.hpp>
#include <graphics/src/image/image_info.hpp>
#include <graphics/src/image/png.hpp>

namespace framework::graphics
{
Image::Image() = default;

Image::Image(const std::vector<Color>& data, std::size_t width, std::size_t height)
    : m_data(data)
    , m_width(width)
    , m_height(height)
{}

Image::LoadResult Image::load(const std::filesystem::path& file)
{
    using namespace details::image;

    auto load_function = [](const std::filesystem::path& f) {
        if (bmp::is_bmp(f)) {
            return bmp::load(f);
        } else if (png::is_png(f)) {
            return png::load(f);
        }

        throw FileTypeError(error::invalid_file_type);
    };

    if (!std::filesystem::exists(file)) {
        return LoadResult::FileNotExists;
    }

    try {
        ImageInfo info = load_function(file);

        m_width  = info.width;
        m_height = info.height;
        m_gamma  = info.gamma;
        m_data   = std::move(info.data);

        return LoadResult::Success;
    } catch (UnsupportedError& e) {
        log::error("Exception:") << e.what();
        return LoadResult::Unsupported;
    } catch (NotImplementedError& e) {
        log::error("Exception:") << e.what();
        return LoadResult::Unsupported;
    } catch (ParsingError& e) {
        log::error("Exception:") << e.what();
        return LoadResult::DataParsingError;
    } catch (FileTypeError& e) {
        log::error("Exception:") << e.what();
        return LoadResult::InvalidFileType;
    } catch (std::exception& e) {
        log::error("Exception:") << e.what();
        return LoadResult::UnknownError;
    }
}

std::size_t Image::width() const
{
    return m_width;
}

std::size_t Image::height() const
{
    return m_height;
}

float Image::gamma() const
{
    return m_gamma;
}

const Color* Image::data() const
{
    return m_data.data();
}

void swap(Image& lhs, Image& rhs) noexcept
{
    using std::swap;

    swap(lhs.m_data, rhs.m_data);
    swap(lhs.m_width, rhs.m_width);
    swap(lhs.m_height, rhs.m_height);
    swap(lhs.m_gamma, rhs.m_gamma);
}

} // namespace framework::graphics
