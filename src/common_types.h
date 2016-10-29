#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

#include <cstdint>

using I8 = std::int8_t;
using I16 = std::int16_t;
using I32 = std::int32_t;
using I64 = std::int64_t;

using U8 = std::uint8_t;
using U16 = std::uint16_t;
using U32 = std::uint32_t;
using U64 = std::uint64_t;

using F32 = float;
using F64 = double;

static_assert(sizeof(I8) == 1, "Size of I8 type is not 1 byte on this platform.");
static_assert(sizeof(I16) == 2, "Size of I16 type is not 2 byte on this platform.");
static_assert(sizeof(I32) == 4, "Size of I32 type is not 4 byte on this platform.");
static_assert(sizeof(I64) == 8, "Size of I64 type is not 8 byte on this platform.");

static_assert(sizeof(U8) == 1, "Size of U8 type is not 1 byte on this platform.");
static_assert(sizeof(U16) == 2, "Size of U16 type is not 2 byte on this platform.");
static_assert(sizeof(U32) == 4, "Size of U32 type is not 4 byte on this platform.");
static_assert(sizeof(U64) == 8, "Size of U64 type is not 8 byte on this platform.");

static_assert(sizeof(F32) == 4, "Size of F32 type is not 4 byte on this platform.");
static_assert(sizeof(F64) == 8, "Size of F64 type is not 8 byte on this platform.");

#endif
