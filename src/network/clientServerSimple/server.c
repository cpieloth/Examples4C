#include <stdio.h>
#include <string.h>

#include <netinet/in.h> // struct sockaddr_in
#include <sys/socket.h>

#include "log.h"
#include "server.h"

static const char SOURCE[] = "server";
svr_bool_t SVR_TRUE = 1;
svr_bool_t SVR_FALSE = 0;

svr_bool_t svr_start(svr_data* const svr)
{
    svr->sd = socket(AF_INET, SOCK_STREAM, 0);
    if (svr->sd == -1)
    {
        log_error(SOURCE, "Could not open socket!");
        return SVR_FALSE;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(svr->PORT);
    if (bind(svr->sd, (struct sockaddr*) &address, sizeof(address)) == -1)
    {
        close(svr->sd);
        log_error(SOURCE, "Could not bind socket!");
        return SVR_FALSE;
    }

    if (listen(svr->sd, svr->MAX_CON) == -1)
    {
        close(svr->sd);
        log_error(SOURCE, "Could not listen on socket!");
        return SVR_FALSE;
    }

    svr->is_running = SVR_TRUE;
    return SVR_TRUE;
}

void svr_stop(svr_data* const svr)
{
    svr->is_running = SVR_FALSE;
}

void svr_run(svr_data* const svr)
{
    struct sockaddr_in clnAddress;
    socklen_t clnAddrLen = sizeof(clnAddress);
    const size_t BUF_SIZE = svr->BUF_SIZE;
    char buffer[BUF_SIZE];

    while (svr->is_running == SVR_TRUE)
    {
        int clnSocket = accept(svr->sd, (struct sockaddr*) &clnAddress, &clnAddrLen);
        if (clnSocket == -1)
        {
            log_error(SOURCE, "Could not open new connection!");
            continue;
        }

        log_info(SOURCE, "New client connected.");

        const ssize_t size = recv(clnSocket, buffer, BUF_SIZE - 1, 0);
        if (size > 0)
        {
            buffer[size] = '\0';
            const char msg_rcvd[] = "Message received: ";
            char msg[size + strlen(msg_rcvd) + 1];
            strcat(msg, msg_rcvd);
            strcat(msg, buffer);
            log_info(SOURCE, msg);

            const char msg_send[] = "server says hello";
            // FIXME(cpieloth): Check sent bytes and may send rest
            send(clnSocket, msg_send, strlen(msg_send), 0);
        }
        else
        {
            log_error(SOURCE, "No message received!");
        }
        close(clnSocket);
    }
}

void svr_close(svr_data* const svr)
{
    svr->is_running = SVR_FALSE;
    if (svr->sd == -1)
    {
        return;
    }
    close(svr->sd, 2);
}
