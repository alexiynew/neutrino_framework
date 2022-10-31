#ifndef SYSTEM_SRC_OSX_OSX_AUTORELEASE_POOL_HPP
#define SYSTEM_SRC_OSX_OSX_AUTORELEASE_POOL_HPP

#import <Foundation/Foundation.h>

namespace neutrino::system::details
{

class AutoreleasePool
{
public:
    AutoreleasePool();
    ~AutoreleasePool();

    AutoreleasePool(const AutoreleasePool&) = delete;
    AutoreleasePool(AutoreleasePool&&)      = delete;

    AutoreleasePool& operator=(const AutoreleasePool&) = delete;
    AutoreleasePool& operator=(AutoreleasePool&&)      = delete;

private:
    NSAutoreleasePool* m_pool = nullptr;
};

} // namespace neutrino::system::details

#endif
