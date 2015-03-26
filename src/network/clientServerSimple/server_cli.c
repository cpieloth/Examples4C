#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include "server.h"

static svr_data server =
{ 0 };

void hdl_sigint(int sig)
{
    svr_stop(&server);
}

int main(void)
{
    signal(SIGINT, hdl_sigint);

    server.PORT = 8000;
    server.BUF_SIZE = 1024;
    server.MAX_CON = 4;

    if (svr_start(&server) != SVR_TRUE)
    {
        printf("Could not start server!\n");
        return EXIT_FAILURE;
    }
    printf("Server started!\n");

    printf("Server is running ...\n");
    svr_run(&server);

    svr_close(&server);
    printf("Server closed!\n");

    return EXIT_SUCCESS;
}
