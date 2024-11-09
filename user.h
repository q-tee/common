#pragma once

/*
 * COMPILE
 * - compilation-time preferences
 */
#pragma region user_compile
// define to additionally wrap the strings
//#define Q_STR(STRING) STRING

// define to overwrite default 'forceinline' function specifier
//#define Q_INLINE inline

// define to overwrite default return address grabber
//#define Q_RETURN_ADDRESS()

// define to overwrite default stack frame address grabber
//#define Q_FRAME_ADDRESS()
#pragma endregion

/*
 * DEBUG
 * - debugging helpers and their behaviour
 */
#pragma region user_debug
/* @section: helpers */
// define to overwrite default debugger break-point
//#define Q_DEBUG_BREAK() __asm int 3;

// define to overwrite default assertion handler
//#include <cassert>
//#define Q_ASSERT(EXPRESSION) assert(EXPRESSION)
#pragma endregion
