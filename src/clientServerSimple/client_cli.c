#include <stdio.h>
#include <stdlib.h>

#include "client.h"

int main(void)
{
	cnt_data client = { 0 };
	client.port = htons(8000);
	inet_aton("127.0.0.1", &client.host);
	client.BUF_SIZE = 1024;
	if (cnt_connect(&client) != CNT_TRUE)
	{
		printf("Could not connect to server!\n");
		return EXIT_FAILURE;
	}
	printf("Connected to server!\n");

	cnt_run(&client);

	cnt_disconnect(&client);
	printf("Disconnected from server!\n");

	return EXIT_SUCCESS;
}
