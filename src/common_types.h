#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

#include <cstdint>

typedef std::int8_t  I8;
typedef std::int16_t I16;
typedef std::int32_t I32;
typedef std::int64_t I64;

typedef std::uint8_t  U8;
typedef std::uint16_t U16;
typedef std::uint32_t U32;
typedef std::uint64_t U64;

typedef float  F32;
typedef double F64;

static_assert(sizeof(I8)  == 1, "Size of I8 type is not 1 byte on this platform.");
static_assert(sizeof(I16) == 2, "Size of I16 type is not 2 byte on this platform.");
static_assert(sizeof(I32) == 4, "Size of I32 type is not 4 byte on this platform.");
static_assert(sizeof(I64) == 8, "Size of I64 type is not 8 byte on this platform.");

static_assert(sizeof(U8)  == 1, "Size of U8 type is not 1 byte on this platform.");
static_assert(sizeof(U16) == 2, "Size of U16 type is not 2 byte on this platform.");
static_assert(sizeof(U32) == 4, "Size of U32 type is not 4 byte on this platform.");
static_assert(sizeof(U64) == 8, "Size of U64 type is not 8 byte on this platform.");

static_assert(sizeof(F32) == 4, "Size of F32 type is not 4 byte on this platform.");
static_assert(sizeof(F64) == 8, "Size of F64 type is not 8 byte on this platform.");

#endif
