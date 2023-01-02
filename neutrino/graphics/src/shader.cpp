#include <fstream>
#include <sstream>

#include <graphics/shader.hpp>

namespace neutrino::graphics
{

bool Shader::set_vertex_source(const std::filesystem::path& filepath)
{
    std::ifstream file(filepath, std::ios::in);
    if (!file) {
        return false;
    }

    std::stringstream source;
    source << file.rdbuf();

    set_vertex_source(source.str());

    return true;
}

void Shader::set_vertex_source(const std::string& source)
{
    m_vertex_source = source;
}

bool Shader::set_fragment_source(const std::filesystem::path& filepath)
{
    std::ifstream file(filepath, std::ios::in);
    if (!file) {
        return false;
    }

    std::stringstream source;
    source << file.rdbuf();

    set_fragment_source(source.str());

    return true;
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
    Shader tmp(std::move(lhs));
    lhs = std::move(rhs);
    rhs = std::move(tmp);
}

} // namespace neutrino::graphics
