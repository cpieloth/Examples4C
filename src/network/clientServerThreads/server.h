#ifndef CLIENTSERVERTHREADS_SERVER_H_
#define CLIENTSERVERTHREADS_SERVER_H_

#include <pthread.h> // running_mutex
#include <netinet/in.h> // in_port_t port

typedef unsigned char svr_bool_t;
extern svr_bool_t SVR_TRUE;
extern svr_bool_t SVR_FALSE;

typedef struct
{
	int sd;
	svr_bool_t is_running;

	in_port_t PORT;
	int MAX_CON;
	size_t BUF_SIZE;

	size_t running_threads;
	pthread_mutex_t running_mutex;
} svr_data;

svr_bool_t svr_start(svr_data* const svr);

void svr_stop(svr_data* const svr);

void svr_run(svr_data* const svr);

void svr_close(svr_data* const svr);

#endif /* CLIENTSERVERTHREADS_SERVER_H_ */
