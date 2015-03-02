#ifndef IO_PERSON_IO_H_
#define IO_PERSON_IO_H_

#include <stdio.h>

#include "person.h"

typedef unsigned char psn_byte_t;

typedef struct
{
	FILE* fp;
	size_t count;
} PersonIO;

PersonIO* psn_io_open_rd(const char* fname);

PersonIO* psn_io_open_wr(const char* fname);

void psn_io_close(PersonIO* const pio);

Person* psn_io_read(PersonIO* const pio);

size_t psn_io_write(PersonIO* const pio, const Person* const p);

void psn_to_byte(psn_byte_t** b, size_t* const len, const Person* const p);

Person* psn_from_byte(const psn_byte_t* const b, size_t len);

#endif /* IO_PERSON_IO_H_ */
