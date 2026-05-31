#pragma once

/*
 * DEBUG
 * - debugging helpers and their behavior
 */
#pragma region user_debug
// define to overwrite default debugger break-point
//#define Q_DEBUG_BREAK() __asm int 3;

// define to overwrite default assertion handler
//#ifdef NDEBUG
//#define Q_ASSERT(EXPRESSION) Q_ASSUME(EXPRESSION) // use assertion as assumption in release builds for optimization opportunities
//#else
//#include <cassert>
//#define Q_ASSERT(EXPRESSION) assert(EXPRESSION)
//#endif
#pragma endregion

/*
 * COMPILER
 * - compilation-time function/variable compiler hints and attributes
 */
#pragma region user_compiler
// define to overwrite default 'forceinline' function attribute
//#define Q_INLINE inline

// define to overwrite default 'noinline' function attribute
//#define Q_NOINLINE

// define to overwrite default 'naked' function attribute
//#define Q_NAKED

// define to overwrite default 'assume' hint
//#define Q_ASSUME

// define to overwrite default 'unreachable' hint
//#define Q_UNREACHABLE()
#pragma endregion

/*
 * OTHER
 * - control over sub-modules configuration and behavior
 */
#pragma region user_other
// define to additionally wrap constant strings used by other sub-modules during run-time evaluation
//#define Q_STR(STRING) STRING

// define configuration macros used by other sub-modules
// ...
#pragma endregion
