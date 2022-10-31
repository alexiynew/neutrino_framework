#include <system/src/osx/osx_autorelease_pool.hpp>

namespace neutrino::system::details
{
AutoreleasePool::AutoreleasePool()
{
    m_pool = [[NSAutoreleasePool alloc] init];
}

AutoreleasePool::~AutoreleasePool()
{
    [m_pool release];
}

} // neutrino::system::details
