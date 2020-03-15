#ifndef _Assert_h_
#define _Assert_h_

#ifdef NDEBUG

	#define Assert(condition) ((void)0)

#else

	#include <Basic/Debug.h>
	#include <Basic/Macros.h>

	#define Assert(condition) \
	{ \
		if (!(condition)) \
		{ \
			DebugMessage("Assert fail: " #condition, __FILE__, MacroValueToString(__LINE__), __FUNCTION__); \
			DebugStop(); \
		} \
	}

#endif

#endif