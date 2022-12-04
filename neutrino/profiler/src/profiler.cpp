#include <chrono>
#include <fstream>
#include <vector>

#include <profiler/profiler.hpp>

namespace
{

using Clock     = std::chrono::high_resolution_clock;
using TimePoint = Clock::time_point;

enum class Phase
{
    Begin,
    End,
};

struct Record
{
    std::string_view name;
    TimePoint time;
    Phase phase;
};

class ProfilerStorage
{
public:
    ProfilerStorage()
    {
        m_records.reserve(1000);
    }

    void begin(std::string_view name)
    {
        m_name  = name;
        m_begin = Clock::now();
        m_records.clear();
    }

    void add(Record record)
    {
        m_records.emplace_back(std::move(record));
    }

    void dump(std::ostream& out)
    {
        out << "{\n";
        out << "  \"traceEvents\": [\n";

        for (auto it = m_records.begin(); it != m_records.end(); ++it) {
            const auto time = duration_cast<std::chrono::microseconds>(it->time - m_begin).count();
            out << "    {";
            out << "\"name\": \"" << it->name << "\"";
            out << ", \"ph\": \"" << (it->phase == Phase::Begin ? "B" : "E") << "\"";
            out << ", \"pid\": \"" << m_name << "\"";
            out << ", \"tid\": 1";
            out << ", \"ts\": " << std::fixed << std::setprecision(12) << time;
            out << "}";
            if (next(it) != m_records.end()) {
                out << ",";
            }
            out << "\n";
        }

        out << "  ],\n";
        out << "}\n";
    }

private:
    std::string_view m_name;
    TimePoint m_begin;
    std::vector<Record> m_records;
};

ProfilerStorage& profiler_instance()
{
    static ProfilerStorage prof;
    return prof;
}

} // namespace

namespace neutrino::profiler
{

ScopeProfilerItem::ScopeProfilerItem(std::string_view name)
    : m_name(name)
{
    profiler_instance().add({m_name, Clock::now(), Phase::Begin});
}

ScopeProfilerItem::~ScopeProfilerItem()
{
    profiler_instance().add({m_name, Clock::now(), Phase::End});
}

void begin_profiling(std::string_view profiler_name)
{
    profiler_instance().begin(profiler_name);
}

ScopeProfilerItem count_scope(std::string_view scope_name)
{
    return ScopeProfilerItem(scope_name);
}

void dump_to_file(const std::filesystem::path& file)
{
    std::ofstream out(file);
    profiler_instance().dump(out);
}

} // namespace neutrino::profiler
