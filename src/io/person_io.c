#include <stdlib.h>
#include <string.h>

#include "log.h"
#include "person_io.h"

PersonIO* psn_io_open_rd(const char* fname)
{
	PersonIO* pio = malloc(sizeof(PersonIO));
	pio->fp = fopen(fname, "r");
	if (pio->fp == NULL)
	{
		log_error(__func__, "Could not open file to read!");
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
		log_error(__func__, "Could not open file to write!");
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
	if (pio == NULL || pio->fp == NULL)
	{
		log_error(__func__, "PersionIO or file pointer is NULL!");
		return 0;
	}

	size_t len = 0;
	size_t len_read = fread(&len, 1, sizeof(len), pio->fp);
	if (len_read != sizeof(len))
	{
		log_error(__func__, "Error reading person length!");
		return NULL;
	}

	psn_byte_t* byte = malloc(len);
	len_read = fread(byte, 1, len, pio->fp);
	if(len != len_read)
	{	free(byte);
		log_error(__func__, "Bytes read and expected are not equals!");
		return NULL;
	}

	Person* p = psn_from_byte(byte, len);
	free(byte);
	if (p == NULL)
	{
		log_error(__func__, "Error parsing person from byte!");
	}

	return p;
}

size_t psn_io_write(PersonIO* const pio, const Person* const p)
{
	if (pio == NULL || pio->fp == NULL)
	{
		log_error(__func__, "PersionIO or file pointer is NULL!");
		return 0;
	}
	if (p == NULL)
	{
		log_error(__func__, "Person is NULL!");
		return 0;
	}

	psn_byte_t* b;
	size_t len;
	psn_to_byte(&b, &len, p);

	size_t len_written = fwrite(&len, 1, sizeof(len), pio->fp);
	if (len_written != sizeof(len))
	{
		log_error(__func__, "Error writing person length!");
		free(b);
		return 0;
	}

	len_written += fwrite(b, 1, len, pio->fp);
	free(b);
	if (len + sizeof(len) == len_written)
	{
		++(pio->count);
		return len;
	}
	else
	{
		log_error(__func__, "Written bytes are wrong!");
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

Person* psn_from_byte(const psn_byte_t* const b, size_t len)
{
	const size_t n_fname = strlen(b) + 1; // \0 -> +1
	const size_t n_sname = strlen(b + n_fname) + 1; // \0 -> +1

	if ((n_fname + n_sname + sizeof(int)) != len) // sizeof(Person.year_of_birth)
	{
		log_error(__func__, "Given length and calculated length are not equals!");
		return NULL;
	}

	Person* p = malloc(sizeof(Person));
	p->forename = malloc(n_fname);
	memcpy(p->forename, b, n_fname);
	p->surname = malloc(n_sname);
	memcpy(p->surname, b + n_fname, n_sname);
	memcpy(&p->year_of_birth, b + n_fname + n_sname, sizeof(p->year_of_birth));

	return p;
}
