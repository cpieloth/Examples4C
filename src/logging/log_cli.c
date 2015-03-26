#include <stdio.h>

#include "log.h"

int main()
{
    printf("Logging example\n");

    printf("\nCall: log_init()\n");
    log_init();

    printf("\nCall: log_error(__func__, \"error ...\")\n");
    log_error(__func__, "error ...");

    printf("\nCall: log_warn(__func__, \"warn ...\")\n");
    log_warn(__func__, "warn ...");

    printf("\nCall: log_info(__func__, \"info <var1>, <var2> ...\", \"arg1\", \"arg2\")\n");
    log_info(__func__, "info %s, %s ...", "arg1", "arg2");

    printf("\nCall: log_debug(__func__, \"debug ...\")\n");
    log_debug(__func__, "debug ...");

    printf("\nCall: log_close()\n");
    log_close();

    return 0;
}
