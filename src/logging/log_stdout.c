#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "log.h"

/**
 * Writes the log message to stdout.
 *
 * \author cpieloth
 */

static const char TAG_ERROR[] = "[ERROR]";
static const char TAG_WARN[] = "[WARN]";
static const char TAG_INFO[] = "[INFO]";
static const char TAG_DEBUG[] = "[DEBUG]";

void log_init()
{
}

static log_tag(const char* tag, const char* src, const char* format, va_list argptr)
{
    // Note: Not thread-safe! printf/vprintf/printf could be merged.
    printf("%s %s: ", tag, src);
    vprintf(format, argptr);
    printf("\n");
}

void log_error(const char* src, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    log_tag(TAG_ERROR, src, format, args);
    va_end(args);
}

void log_warn(const char* src, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    log_tag(TAG_WARN, src, format, args);
    va_end(args);
}

void log_info(const char* src, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    log_tag(TAG_INFO, src, format, args);
    va_end(args);
}

void log_debug(const char* src, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    log_tag(TAG_DEBUG, src, format, args);
    va_end(args);
}

void log_close()
{
}
