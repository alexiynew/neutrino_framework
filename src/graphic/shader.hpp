/// @file
/// @brief Shader class.
/// @author Fedorov Alexey
/// @date 16.08.2018

#ifndef FRAMEWORK_GRAPHIC_SHADER_HPP
#define FRAMEWORK_GRAPHIC_SHADER_HPP

#include <string>
#include <vector>

#include <common/types.hpp>

namespace framework::graphic
{
class shader final
{
public:
    struct attribute
    {
        uint32 location;
        std::string name;
    };

    template <typename T>
    struct span
    {
        T* first;
        int32 count;
    };

    shader();

    ~shader();

    void add_vertex_source(std::string source);
    void add_fragment_source(std::string source);

    void bind_attribute(attribute attdib);

    void compile();

    void use();

    int32 uniform_location(const std::string& name);
    /*
        template <typename T>
        void set_uniform(int32 location, T value1)
        {
            details::set_uniform(location, value1);
        }

        template <typename T>
        void set_uniform(int32 location, span<T> values);

        template <typename T>
        void set_uniform(int32 location, T value1, T value2);

        template <typename T>
        void set_uniform(int32 location, T value1, T value2, T value3);

        template <typename T>
        void set_uniform(int32 location, T value1, T value2, T value3, T value4);

        template <uint32 N, typename T, template <uint32, typename> typename vector>
        void set_uniform(int32 location, span<vector<N, T>> values);

        template <uint32 C, uint32 R, typename T, template <uint32, uint32, typename> typename matrix>
        void set_uniform(int32 location, span<matrix<C, R, T>> values);
        */

private:
    void clear();

    std::vector<std::string> m_vertex_sources;
    std::vector<std::string> m_fragment_sources;
    std::vector<attribute> m_attributes;

    uint32 m_vertex_shader   = 0;
    uint32 m_fragment_shader = 0;
    uint32 m_program         = 0;
};

} // namespace framework::graphic

#endif
