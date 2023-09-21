#pragma once

// Faster Builds with Smaller Header Files
// https://msdn.microsoft.com/en-us/library/windows/desktop/aa383745%28v=vs.85%29.aspx

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#ifndef NOMINMAX
#define NOMINMAX 1
#endif
#define NOATOM
#define NOGDI
#define NOGDICAPMASKS
#define NOMETAFILE
#define NOMSG
#define NOOPENFILE
#define NORASTEROPS
#define NOSCROLL
#define NOSOUND
#define NOSYSMETRICS
#define NOTEXTMETRIC
#define NOWH
#define NOCOMM
#define NOKANJI
#define NOCRYPT
#define NOMCX

#include <windows.h>

#undef small
#undef min
#undef max
#undef abs
#undef NOATOM
#undef NOGDI
#undef NOGDICAPMASKS
#undef NOMETAFILE
#undef NOMSG
#undef NOOPENFILE
#undef NORASTEROPS
#undef NOSCROLL
#undef NOSOUND
#undef NOSYSMETRICS
#undef NOTEXTMETRIC
#undef NOWH
#undef NOCOMM
#undef NOKANJI
#undef NOCRYPT
#undef NOMCX
