#include <stdio.h>
#include <stdlib.h>

#include "person.h"
#include "person_io.h"

int main()
{
	Person* p1 = psn_create("foo", "barr", 42);

	char* p1_str = psn_to_string(p1);
	printf("%s\n", p1_str);

	psn_byte_t* psn_byte;
	size_t psn_byte_len;
	psn_to_byte(&psn_byte, &psn_byte_len, p1);
	printf("%zu\n", psn_byte_len);

	Person* p2 = psn_from_byte(psn_byte);
	char* p2_str = psn_to_string(p2);
	printf("%s\n", p2_str);

	free(p2_str);
	psn_free(p2);
	free(psn_byte);
	free(p1_str);
	psn_free(p1);
}
