#include <stdio.h>
#include "log.h"

static const char TAG_INFO[] = "INFO";
static const char TAG_ERROR[] = "ERROR";

static void _log(const char* tag, const char* src, const char* msg)
{
	printf("[%s] %s: %s\n", tag, src, msg);
}
void log_info(const char* src, const char* msg)
{
	_log(TAG_INFO, src, msg);
}

void log_error(const char* src, const char* msg)
{
	_log(TAG_ERROR, src, msg);
}
