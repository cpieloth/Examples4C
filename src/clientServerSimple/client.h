#ifndef CLIENTSERVERSIMPLE_CLIENT_H_
#define CLIENTSERVERSIMPLE_CLIENT_H_

#include <netinet/in.h> // sockaddr_in

typedef unsigned char cnt_bool_t;
extern cnt_bool_t CNT_TRUE;
extern cnt_bool_t CNT_FALSE;

typedef struct
{
	int sd;
	in_addr_t host;
	in_port_t port;
	size_t BUF_SIZE;
} cnt_data;

cnt_bool_t cnt_connect(cnt_data* const cnt);

void cnt_run(cnt_data* const svr);

void cnt_disconnect(cnt_data* const svr);

#endif /* CLIENTSERVERSIMPLE_CLIENT_H_ */
