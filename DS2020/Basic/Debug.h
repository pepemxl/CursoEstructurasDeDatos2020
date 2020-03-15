#ifndef _Debug_h_
#define _Debug_h_

#include <Basic/Macros.h>

#define DebugPosition(message) DebugMessage(message, __FILE__, MacroValueToString(__LINE__), __FUNCTION__)

void DebugMessage(const char* message) throw();

void DebugMessage(const char* message, const char* source, const char* line, const char* function) throw();

void DebugStop() throw();

#endif