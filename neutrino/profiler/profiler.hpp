#ifndef FRAMEWORK_PROFILER_PROFILER_HPP
#define FRAMEWORK_PROFILER_PROFILER_HPP

#include <filesystem>
#include <string_view>

namespace framework::profiler
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup profiler_module
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ScopeProfilerItem
{
public:
    explicit ScopeProfilerItem(std::string_view name);

    ScopeProfilerItem(const ScopeProfilerItem&) = delete;
    ScopeProfilerItem(ScopeProfilerItem&&)      = delete;

    ScopeProfilerItem& operator=(const ScopeProfilerItem&) = delete;
    ScopeProfilerItem& operator=(ScopeProfilerItem&&) = delete;

    ~ScopeProfilerItem();

private:
    std::string_view m_name;
};

void begin_profiling(std::string_view profiler_name);

ScopeProfilerItem count_scope(std::string_view scope_name);

void dump_to_file(const std::filesystem::path& file);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace framework::profiler

#endif
