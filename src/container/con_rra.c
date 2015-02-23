/**
 * Implemtation of con_rra.h
 *
 * \author	executor
 */

#include <stdlib.h>
#include <stdio.h>

#include "con_rra.h"

con_rra_t* con_rraCreate(const long size)
{
	con_rra_t* this = malloc(sizeof(con_rra_t));
	this->pos = 0;
	this->size = size;
	this->values = malloc(size * sizeof(con_rraType_t));
	return this;
}

long con_rraPut(con_rra_t* const this, const con_rraType_t value)
{
	this->values[this->pos] = value;
	this->pos = (this->pos + 1) % this->size;
	return this->pos;
}

con_rraType_t con_rraGet(const con_rra_t* const this, long pos)
{
	pos = pos % this->size;
	return this->values[pos];
}

long con_rraSet(con_rra_t* const this, long pos, const con_rraType_t value)
{
	pos = pos % this->size;
	this->values[pos] = value;
	return pos;
}

long con_rraSize(const con_rra_t* const this)
{
	return this->size;
}

void con_rraPrint(const con_rra_t* const this)
{
	long i;
	printf("RRA:");
	for (i = 0; i < this->size; i++)
	{
		printf(" %d", this->values[i]);
	}
	printf("\n");
}

void con_rraFree(con_rra_t* this)
{
	free(this->values);
	free(this);
}
