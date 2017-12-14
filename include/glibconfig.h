//#ifndef UNDER_WIN32
//#define UNDER_MRE
//#endif

#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "stdarg.h"
#include "ctype.h"

/* Define to empty if the keyword does not work.  */
//#undef const

/* Define as __inline if that's what the C compiler calls it.  */
#define inline


/* The number of bytes in a char.  */
#define SIZEOF_CHAR 1

/* The number of bytes in a int.  */
#define SIZEOF_INT 4

/* The number of bytes in a long.  */
#define SIZEOF_LONG 4

/* The number of bytes in a long long.  */
#define SIZEOF_LONG_LONG 8

/* The number of bytes in a short.  */
#define SIZEOF_SHORT 2

/* The number of bytes in a void *.  */
#define SIZEOF_VOID_P 4

/* Define if you have the memmove function.  */
#undef HAVE_MEMMOVE
#define HAVE_MEMMOVE

/* Define if you have the strcasecmp function.  */
#undef HAVE_STRCASECMP

void g_log_init(char* log_file);
int g_log_enabled(char* file, int line, char* fun, char* level);
void g_log(char* fmt, ...);

//#define g_log_fatal if (g_log_enabled(__FILE__, __LINE__, __FUNCTION__, "FATAL")) g_log
//#define g_log_error if (g_log_enabled(__FILE__, __LINE__, __FUNCTION__, "ERROR")) g_log
//#define g_log_warn if (g_log_enabled(__FILE__, __LINE__, __FUNCTION__, "WARN")) g_log
//#define g_log_info if (g_log_enabled(__FILE__, __LINE__, __FUNCTION__, "INFO")) g_log
//#define g_log_debug if (g_log_enabled(__FILE__, __LINE__, __FUNCTION__, "DEBUG")) g_log

#define g_warning g_log_warn
#define g_error g_log_error
#define g_log_fatal printf
#define g_log_error printf
#define g_log_warn printf
#define g_log_info printf
#define g_log_debug printf

#define g_print printf
