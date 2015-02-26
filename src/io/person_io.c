#include <stdlib.h>
#include <string.h>

#include "person_io.h"

PersonIO* psn_io_open_rd(const char* fname)
{
	PersonIO* pio = malloc(sizeof(PersonIO));
	pio->fp = fopen(fname, "r");
	if (pio->fp == NULL)
	{
		// TODO error log
		free(pio);
		pio = NULL;
	}
	return pio;
}

PersonIO* psn_io_open_wr(const char* fname)
{
	PersonIO* pio = malloc(sizeof(PersonIO));
	pio->count = 0;
	pio->fp = fopen(fname, "w");
	if (pio->fp == NULL)
	{
		// TODO error log
		free(pio);
		pio = NULL;
	}
	return pio;
}

void psn_io_close(PersonIO* const pio)
{
	if (pio->fp != NULL)
	{
		fclose(pio->fp);
	}
	free(pio);
}

Person* psn_io_read(PersonIO* const pio)
{
	Person* p = NULL;
	// TODO read
	// 1) read first size_t to len
	// 2) alloc len bytes
	// 3) read len bytes
	// 4) psn_from_byte
	return p;
}

size_t psn_io_write(PersonIO* const pio, const Person* const p)
{
	psn_byte_t* b;
	size_t len;
	psn_to_byte(&b, &len, p);

	// TODO write len before person data. len|person|len|person|...
	const size_t len_written = fwrite(b, 1, len, pio->fp);
	if (len == len_written)
	{
		++(pio->count);
		return len;
	}
	else
	{
		// TODO error log
		return 0;
	}
}

void psn_to_byte(psn_byte_t** b, size_t* const len, const Person* const p)
{
	const size_t n_fname = strlen(p->forename) + 1; // \0 -> +1
	const size_t n_sname = strlen(p->surname) + 1; // \0 -> +1
	const size_t n_yob = sizeof(p->year_of_birth);

	*len = 0;
	*len += n_fname;
	*len += n_sname;
	*len += n_yob;

	*b = malloc(*len);
	memcpy(*b, p->forename, n_fname);
	memcpy(*b + n_fname, p->surname, n_sname);
	memcpy(*b + n_fname + n_sname, &p->year_of_birth, n_yob);
}

Person* psn_from_byte(const psn_byte_t* const b)
{
	const size_t n_fname = strlen(b) + 1; // \0 -> +1
	const size_t n_sname = strlen(b + n_fname) + 1; // \0 -> +1

	Person* p = malloc(sizeof(Person));
	p->forename = malloc(n_fname);
	memcpy(p->forename, b, n_fname);
	p->surname = malloc(n_sname);
	memcpy(p->surname, b + n_fname, n_sname);
	memcpy(&p->year_of_birth, b + n_fname + n_sname, sizeof(p->year_of_birth));

	return p;
}
