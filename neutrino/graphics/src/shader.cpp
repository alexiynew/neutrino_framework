#include <fstream>
#include <sstream>

#include <graphics/shader.hpp>

namespace framework::graphics
{

Shader::Shader(const Shader& other)
    : m_vertex_source(other.m_vertex_source)
    , m_fragment_source(other.m_fragment_source)
{}

Shader& Shader::operator=(const Shader& other)
{
    using std::swap;

    Shader tmp(other);
    swap(*this, tmp);
    return *this;
}

Shader::Shader(Shader&& other) noexcept
{
    swap(*this, other);
}

Shader& Shader::operator=(Shader&& other) noexcept
{
    swap(*this, other);
    return *this;
}

bool Shader::load_vertex_source(const std::string& filename)
{
    std::ifstream file(filename, std::ios::in);
    if (!file) {
        return false;
    }

    std::stringstream source;
    source << file.rdbuf();

    set_vertex_source(source.str());

    return true;
}

bool Shader::load_fragment_source(const std::string& filename)
{
    std::ifstream file(filename, std::ios::in);
    if (!file) {
        return false;
    }

    std::stringstream source;
    source << file.rdbuf();

    set_fragment_source(source.str());

    return true;
}

void Shader::set_vertex_source(const std::string& source)
{
    m_vertex_source = source;
}

void Shader::set_fragment_source(const std::string& source)
{
    m_fragment_source = source;
}

void Shader::clear()
{
    m_vertex_source.clear();
    m_fragment_source.clear();
}

InstanceId Shader::instance_id() const
{
    return m_instance_id;
}

const std::string& Shader::vertex_source() const
{
    return m_vertex_source;
}

const std::string& Shader::fragment_source() const
{
    return m_fragment_source;
}

void swap(Shader& lhs, Shader& rhs) noexcept
{
    using std::swap;
    swap(lhs.m_vertex_source, rhs.m_vertex_source);
    swap(lhs.m_fragment_source, rhs.m_fragment_source);
}

} // namespace framework::graphics
