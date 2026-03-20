#pragma once

#pragma region common_pre_macro
#define _Q_INTERNAL_CONCATENATE(LEFT, RIGHT) LEFT##RIGHT
#define _Q_INTERNAL_STRINGIFY(NAME) #NAME
#define _Q_INTERNAL_UNPARENTHESIZE(...) __VA_ARGS__

// convert plain text to a string
#define Q_STRINGIFY(NAME) _Q_INTERNAL_STRINGIFY(NAME)
// concatenate plain text
#define Q_CONCATENATE(LEFT, RIGHT) _Q_INTERNAL_CONCATENATE(LEFT, RIGHT)
// append wide-string literal to macro of string value
#define Q_WIDE(STRING) _Q_INTERNAL_CONCATENATE(L, STRING)
// unparenthesize variadic arguments
#define Q_UNPARENTHESIZE(...) _Q_INTERNAL_UNPARENTHESIZE(__VA_ARGS__)
#pragma endregion

#pragma region common_architecture_specific
// @todo: distinguish between arm and x86 properly
#if defined(i386) || defined(__i386__) || defined(__i486__) || defined(__i586__) || defined(__i686__) || defined(__i386) || defined(_M_IX86) || defined(_X86_) || defined(__I86__) || defined(__INTEL__) || defined(__THW_INTEL__)
#define Q_ARCH_X32 // x86_32
#define Q_ARCH_BIT 32
#elif (defined(__x86_64__) && !defined(__ILP32__)) || defined(__x86_64) || defined(__LP64__) || defined(__amd64__) || defined(__amd64) || defined(_M_X64) || defined(__ia64) || defined(_M_IA64)
#define Q_ARCH_X64 // x86_64
#define Q_ARCH_BIT 64
#elif defined(__arm__) || defined(_M_ARM)
#define Q_ARCH_ARM
#define Q_ARCH_BIT 32
#elif defined(__arm64) || defined(__aarch64__) || defined(_M_ARM64)
#define Q_ARCH_ARM64
#define Q_ARCH_BIT 64
#else
#error "could not determine the target architecture, consider define it manually!"
#endif

// determine available instruction-sets
// x86 extended instruction sets
#if defined(__MIC__)
#define Q_ISA_MIC
#define Q_ISA_AVX2
#define Q_ISA_AVX
#define Q_ISA_FMA
#define Q_ISA_SSSE4_2
#define Q_ISA_SSSE4_1
#define Q_ISA_SSSE3
#define Q_ISA_SSE3
#define Q_ISA_SSE2
#define Q_ISA_SSE
#define Q_ISA_MMX
#elif defined(__AVX2__)
#define Q_ISA_AVX2
#define Q_ISA_AVX
#define Q_ISA_FMA
#define Q_ISA_SSSE4_2
#define Q_ISA_SSSE4_1
#define Q_ISA_SSSE3
#define Q_ISA_SSE3
#define Q_ISA_SSE2
#define Q_ISA_SSE
#define Q_ISA_MMX
#elif defined (__AVX__)
#define Q_ISA_AVX
#define Q_ISA_FMA
#define Q_ISA_SSSE4_2
#define Q_ISA_SSSE4_1
#define Q_ISA_SSSE3
#define Q_ISA_SSE3
#define Q_ISA_SSE2
#define Q_ISA_SSE
#define Q_ISA_MMX
#elif defined(__FMA__)
#define Q_ISA_FMA
#define Q_ISA_SSSE4_2
#define Q_ISA_SSSE4_1
#define Q_ISA_SSSE3
#define Q_ISA_SSE3
#define Q_ISA_SSE2
#define Q_ISA_SSE
#define Q_ISA_MMX
#elif defined(__SSSE4_2__)
#define Q_ISA_SSSE4_2
#define Q_ISA_SSSE4_1
#define Q_ISA_SSSE3
#define Q_ISA_SSE3
#define Q_ISA_SSE2
#define Q_ISA_SSE
#define Q_ISA_MMX
#elif defined(__SSSE4_1__)
#define Q_ISA_SSSE4_1
#define Q_ISA_SSSE3
#define Q_ISA_SSE3
#define Q_ISA_SSE2
#define Q_ISA_SSE
#define Q_ISA_MMX
#elif defined(__SSSE3__)
#define Q_ISA_SSSE3
#define Q_ISA_SSE3
#define Q_ISA_SSE2
#define Q_ISA_SSE
#define Q_ISA_MMX
#elif defined(__SSE3__)
#define Q_ISA_SSE3
#define Q_ISA_SSE2
#define Q_ISA_SSE
#define Q_ISA_MMX
#elif defined(__SSE2__) || _M_IX86_FP == 2 || defined(Q_ARCH_X64)
#define Q_ISA_SSE2
#define Q_ISA_SSE
#define Q_ISA_MMX
#elif defined(__SSE__) || _M_IX86_FP == 1
#define Q_ISA_SSE
#define Q_ISA_MMX
#elif defined(__MMX__)
#define Q_ISA_MMX
#endif
// x86 AMD extended instructions sets
#if defined(__XOP__)
#define Q_ISA_AMD_XOP
#define Q_ISA_AMD_FMA4
#define Q_ISA_AMD_SSE4A
#elif defined(__FMA4__)
#define Q_ISA_AMD_FMA4
#define Q_ISA_AMD_SSE4A
#elif defined(__SSE4A__)
#define Q_ISA_AMD_SSE4A
#endif
// ARM extended instruction sets
#if defined(__ARM_NEON__) || defined(Q_ARCH_ARM64)
#define Q_ISA_NEON
#endif
#pragma endregion

#pragma region common_os_specific
#if defined(_WIN32) || defined(_WIN64)
#define Q_OS_WINDOWS
#endif
#if defined(__linux__) || defined(__unix__) || defined(__unix)
#define Q_OS_LINUX
#endif
#if defined(__APPLE__)
#define Q_OS_MACOS
#endif
#pragma endregion

#pragma region common_compiler_specific
// @note: clang-cl have defined both 'Q_COMPILER_CLANG' and 'Q_COMPILER_MSC'
#if defined(_MSC_VER)
#define Q_COMPILER_MSC
#endif
#if defined(__clang__)
#define Q_COMPILER_CLANG
#elif defined(__GNUC__) || defined(__GNUG__)
#define Q_COMPILER_GCC
#endif

#ifdef __has_include
#define Q_HAS_INCLUDE(INCLUDE) __has_include(INCLUDE)
#else
#define Q_HAS_INCLUDE(INCLUDE) 0
#endif

#ifdef __has_feature
#define Q_HAS_FEATURE(FEATURE) __has_feature(FEATURE)
#else
#define Q_HAS_FEATURE(FEATURE) 0
#endif

#ifdef __has_attribute
#define Q_HAS_ATTRIBUTE(ATTRIBUTE) __has_attribute(ATTRIBUTE)
#else
#define Q_HAS_ATTRIBUTE(ATTRIBUTE) 0
#endif

#ifdef __has_builtin
#define Q_HAS_BUILTIN(BUILTIN) __has_builtin(BUILTIN)
#else
#define Q_HAS_BUILTIN(BUILTIN) 0
#endif

#if defined(Q_COMPILER_MSC) || defined(Q_COMPILER_CLANG)
#define Q_NAKED __declspec(naked)
#elif defined(Q_COMPILER_GCC)
#define Q_NAKED __attribute__((naked))
#endif
#pragma endregion

// used: user defined overrides
#include "user.h"

#pragma region common_implementation_specific
// calculate elements count of the fixed-size C array
#define Q_ARRAYSIZE(ARRAY) (sizeof(ARRAY) / sizeof(ARRAY[0]))

// calculate the offset of a struct member variable, in bytes
#if defined(_CRT_USE_BUILTIN_OFFSETOF) || Q_HAS_BUILTIN(__builtin_offsetof)
#define Q_OFFSETOF(STRUCT, MEMBER) __builtin_offsetof(STRUCT, MEMBER)
#else
// used: [stl] addressof
#include <memory>
#define Q_OFFSETOF(STRUCT, MEMBER) reinterpret_cast<std::size_t>(std::addressof(static_cast<STRUCT*>(nullptr)->MEMBER))
#endif
#pragma endregion

#pragma region common_user_specific
#ifndef Q_STR
#define Q_STR(STRING) STRING
#endif

#ifndef Q_INLINE
#if defined(Q_COMPILER_CLANG)
#define Q_INLINE [[clang::always_inline]]
#elif defined(Q_COMPILER_MSC)
#define Q_INLINE [[msvc::forceinline]]
#elif defined(Q_COMPILER_GCC)
#define Q_INLINE __attribute__((always_inline))
#else
#define Q_INLINE
#endif
#endif

#ifndef Q_NOINLINE
#if defined(Q_COMPILER_CLANG)
#define Q_NOINLINE [[clang::noinline]]
#elif defined(Q_COMPILER_MSC)
#define Q_NOINLINE [[msvc::noinline]]
#elif defined(Q_COMPILER_GCC)
#define Q_NOINLINE __attribute__((noinline))
#else
#define Q_NOINLINE
#endif
#endif

#ifndef Q_DEBUG_BREAK
#if defined(Q_COMPILER_MSC)
#define Q_DEBUG_BREAK() ::__debugbreak()
#elif Q_HAS_BUILTIN(__builtin_debugtrap)
#define Q_DEBUG_BREAK() ::__builtin_debugtrap()
#elif Q_HAS_BUILTIN(__builtin_trap)
#define Q_DEBUG_BREAK() ::__builtin_trap()
#else
// @todo: use #warning instead of #error
#error "it is expected you to define Q_DEBUG_BREAK() into something that will break in a debugger!"
#define Q_DEBUG_BREAK()
#endif
#endif

#ifndef Q_ASSERT
#ifdef _DEBUG
#define Q_ASSERT(EXPRESSION) static_cast<void>(!!(EXPRESSION) || (Q_DEBUG_BREAK(), false))
#else
// disable assertion for release builds
#define Q_ASSERT(EXPRESSION) static_cast<void>(0)
#endif
#endif
#pragma endregion

#pragma region common_class
/*
 * explicitly delete the following constructors, to prevent attempts on using them:
 * constructor, move-constructor, copy-constructor
 */
#define Q_CLASS_NO_CONSTRUCTOR(CLASS)	\
CLASS() = delete;						\
CLASS(CLASS&&) = delete;				\
CLASS(const CLASS&) = delete;

 /*
  * explicitly delete the following assignment operators, to prevent attempts on using them:
  * move-assignment, copy-assignment
  */
#define Q_CLASS_NO_ASSIGNMENT(CLASS)	\
CLASS& operator=(CLASS&&) = delete;		\
CLASS& operator=(const CLASS&) = delete;

  // explicitly delete any class initializer to prevent attempts on using them
#define Q_CLASS_NO_INITIALIZER(CLASS)	\
Q_CLASS_NO_CONSTRUCTOR(CLASS)			\
Q_CLASS_NO_ASSIGNMENT(CLASS)

// explicitly delete class heap allocator and deallocator, to prevent attempts on using class at heap memory
#define Q_CLASS_NO_ALLOC()								\
void* operator new(const std::size_t nSize) = delete;	\
void operator delete(void* pMemory) = delete;
#pragma endregion
