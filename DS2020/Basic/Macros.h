#ifndef _Macros_h_
#define _Macros_h_

#include <stdlib.h>

// Convert to string
#define MacroToString(a) #a
#define MacroValueToString(a) MacroToString(a)

// Read environment variables
#define GetEnvInteger(env_name) ((getenv(#env_name) != (char*)0) ? atoi(getenv(#env_name)) : env_name)
#define GetEnvFloat(env_name) ((getenv(#env_name) != (char*)0) ? atof(getenv(#env_name)) : env_name)
// Example:
//   #define LOG_LEVEL 2
//   int log_level = GetEnvInteger(LOG_LEVEL);
// Returns the value of the environment variable LOG_LEVEL or the default value defined in LOG_LEVEL

#endif
