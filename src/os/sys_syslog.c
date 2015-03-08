#include <stdio.h>
#include <stdlib.h>
#include <sys/syslog.h>

int main()
{
	char ident[] = "Examples4C";
	openlog(ident, LOG_CONS | LOG_PID, LOG_LOCAL0);

	char log_msg1[] = "My first info syslog in C.";
	printf("%s\n", log_msg1);
	syslog(LOG_INFO, log_msg1);

	char log_msg2[] = "My first warning syslog in C.";
	printf("%s\n", log_msg2);
	syslog(LOG_WARNING, log_msg2);

	closelog();

	printf("Now, check: /var/log/syslog\n");
	return EXIT_SUCCESS;
}
