/// @file
/// @brief The realisation details of the logging system.
/// @author Fedorov Alexey
/// @date 03.03.2018

#include <log/log.hpp>
#include <log/log_details.hpp>

namespace {

constexpr size_t default_log_buffer_size = 1024;
}

namespace framework {

namespace log {

namespace log_details {

#pragma region log_buffer

class log_buffer : public std::streambuf
{
public:
    log_buffer(::framework::log::severity_level level, const std::string& tag, size_t buffer_size = ::default_log_buffer_size)
        : m_level(level)
        , m_tag(tag)
        , m_buffer_size(buffer_size)
        , m_buffer(new char_type[buffer_size])
    {
        reset_pointers();
    }

    ~log_buffer()
    {
        sync();
    }

protected:
    int overflow(int character) override
    {
        if (character == traits_type::eof()) {
            return traits_type::eof();
        }

        if (sync() != 0) {
            return traits_type::eof();
        }

        return sputc(static_cast<char>(character));
    }

    int sync() override
    {
        if (pptr() == pbase()) {
            return 0;
        }

        const ptrdiff_t size = pptr() - pbase();

        ::framework::log::logger()->add_message(m_level, m_tag, std::string(m_buffer.get(), size));

        reset_pointers();

        return 0;
    }

private:
    const ::framework::log::severity_level m_level;
    const std::string m_tag;
    const size_t m_buffer_size;
    std::unique_ptr<char_type[]> m_buffer;

    void reset_pointers()
    {
        setp(m_buffer.get(), m_buffer.get() + m_buffer_size);
    }
};

#pragma endregion

log_ostream::log_ostream(::framework::log::severity_level level, const std::string& tag)
    : std::ostream(nullptr)
    , m_buffer(std::make_unique<log_buffer>(level, tag))
{
    rdbuf(m_buffer.get());
}

log_ostream::~log_ostream() = default;

log_ostream::log_ostream(log_ostream&& other)
    : m_buffer(std::move(other.m_buffer))
{
    rdbuf(m_buffer.get());
}

log_ostream& log_ostream::operator=(log_ostream&& other)
{
    std::ostream::operator=(std::move(other));

    m_buffer = std::move(other.m_buffer);

    return *this;
}

} // namespace log_details

} // namespace log

} // namespace framework
