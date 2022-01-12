#include <graphics/texture.hpp>
#include <graphics/uniform.hpp>

namespace framework::graphics
{

TextureBinding::TextureBinding(const Texture& texture)
    : m_texture(texture.instance_id())
{}

InstanceId TextureBinding::texture() const
{
    return m_texture;
}

const std::string& Uniform::name() const
{
    return m_name;
}

const UniformValue& Uniform::value() const
{
    return m_value;
}

} // namespace framework::graphics
