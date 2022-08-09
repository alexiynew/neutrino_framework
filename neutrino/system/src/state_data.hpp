#ifndef SYSTEM_SRC_STATE_DATA_HPP
#define SYSTEM_SRC_STATE_DATA_HPP

namespace framework::system::details
{

struct StateData
{
    bool should_close   = false;
    bool cursor_grabbed = false;
};

} // namespace framework::system::details

#endif