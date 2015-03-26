#include <stdio.h>
#include <string.h>
#include <sys/socket.h>

#include "client.h"
#include "log.h"

static const char SOURCE[] = "client";

cnt_bool_t CNT_TRUE = 1;
cnt_bool_t CNT_FALSE = 0;

cnt_bool_t cnt_connect(cnt_data* const cnt)
{
    cnt->sd = socket(AF_INET, SOCK_STREAM, 0);
    if (cnt->sd == -1)
    {
        log_error(SOURCE, "Could not open socket!");
        return CNT_FALSE;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = cnt->port;
    address.sin_addr.s_addr = cnt->host;
    if (connect(cnt->sd, (struct sockaddr*) &address, sizeof(address)) == -1)
    {
        log_error(SOURCE, "Could not connect to server!");
        return CNT_FALSE;
    }
    return CNT_TRUE;
}

void cnt_run(cnt_data* const cnt)
{
    const size_t BUF = cnt->BUF_SIZE;
    char buffer[BUF];

    printf("Message to send: ");
    fgets(buffer, BUF, stdin);
    send(cnt->sd, buffer, strlen(buffer), 0);

    const int size = recv(cnt->sd, buffer, BUF - 1, 0);
    if (size > 0)
    {
        buffer[size] = '\0';
        const char msg_rcvd[] = "Message received: ";
        char msg[size + strlen(msg_rcvd) + 1];
        msg[0] = '\0';
        strcat(msg, msg_rcvd);
        strcat(msg, buffer);
        log_info(SOURCE, msg);
    }
    else
    {
        log_error(SOURCE, "No message received!");
    }
}

void cnt_disconnect(cnt_data* const cnt)
{
    if (cnt->sd == -1)
    {
        return;
    }
    shutdown(cnt->sd, SHUT_RDWR);
}
