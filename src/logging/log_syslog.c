#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <sys/syslog.h>

#include "log.h"

/**
 * Passes the logs to syslog.
 *
 * \author cpieloth
 */

// Pointer ident will be retained internally by the Syslog routines.
// You must not free the memory that ident points to.
static const char ident[] = "Examples4C";

void log_init()
{
	openlog(ident, LOG_CONS | LOG_PID, LOG_LOCAL0);
}

static log_tag(int log_level, const char* src, const char* format, va_list argptr)
{
	const size_t n_prefix = strlen(src) + 1 + 1 + 1; // SRC:_\0
	char prefix[n_prefix];
	sprintf(prefix, "%s: ", src);

	char suffix[1024];
	vsnprintf(suffix, sizeof(suffix), format, argptr);

	const size_t n_suffix = strlen(suffix);
	char log_msg[n_prefix + n_suffix + 1];
	log_msg[0] = '\0';
	strcat(log_msg, prefix);
	strcat(log_msg, suffix);

	syslog(log_level, "%s", log_msg);
}

void log_error(const char* src, const char* format, ...)
{
	va_list args;
	va_start(args, format);
	log_tag(LOG_ERR, src, format, args);
	va_end(args);
}

void log_warn(const char* src, const char* format, ...)
{
	va_list args;
	va_start(args, format);
	log_tag(LOG_WARNING, src, format, args);
	va_end(args);
}

void log_info(const char* src, const char* format, ...)
{
	va_list args;
	va_start(args, format);
	log_tag(LOG_INFO, src, format, args);
	va_end(args);
}

void log_debug(const char* src, const char* format, ...)
{
	va_list args;
	va_start(args, format);
	log_tag(LOG_DEBUG, src, format, args);
	va_end(args);
}

void log_close()
{
	closelog();
}
