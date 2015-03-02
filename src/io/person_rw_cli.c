#include <stdio.h>
#include <stdlib.h>

#include "person.h"
#include "person_io.h"

void print_person(const Person* const p)
{
	char* p_str = psn_to_string(p);
	printf("%s\n", p_str);
	free(p_str);
}

int main()
{
	const char fname[] = "/tmp/persons.dat";

	Person* const p1 = psn_create("foo", "barr", 42);
	print_person(p1);

	Person* const p2 = psn_create("foo", "bazz", 23);
	print_person(p2);

	PersonIO* const pio_write = psn_io_open_wr(fname);
	if (pio_write == NULL)
	{
		printf("Could not open file to write!\n");
		psn_free(p1);
		psn_free(p2);
		return EXIT_FAILURE;
	}

	if (psn_io_write(pio_write, p1) == 0 || psn_io_write(pio_write, p2) == 0)
	{
		printf("Error writing p1 or p2 to file!\n");
		psn_free(p1);
		psn_free(p2);
		psn_io_close(pio_write);
		return EXIT_FAILURE;
	}

	psn_free(p1);
	psn_free(p2);
	psn_io_close(pio_write);
	printf("Wrote two persons to file.\n");

	PersonIO* const pio_read = psn_io_open_rd(fname);
	if (pio_read == NULL)
	{
		printf("Could not open file to read!\n");
		return EXIT_FAILURE;
	}

	Person* p = psn_io_read(pio_read);
	if (p != NULL)
	{
		print_person(p);
	}
	else
	{
		printf("Error reading person from file!\n");
	}

	p = psn_io_read(pio_read);
	if (p != NULL)
	{
		print_person(p);
	}
	else
	{
		printf("Error reading person from file!\n");
	}

	psn_io_close(pio_read);

	return EXIT_SUCCESS;
}
