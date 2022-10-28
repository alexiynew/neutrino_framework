#include <graphics/texture.hpp>
#include <graphics/uniform.hpp>

namespace framework::graphics
{

const std::string& Uniform::name() const
{
    return m_name;
}

const UniformValue& Uniform::value() const
{
    return m_value;
}

} // namespace framework::graphics
