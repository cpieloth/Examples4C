/**
 * Implementation of con_list.h
 *
 * \author cpieloth
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "con_list.h"

con_list_t* con_listCreate()
{
	con_list_t* this = malloc(sizeof(con_list_t));
	this->begin = NULL;
	this->end = NULL;
	this->size = 0;
	return this;
}

void con_listAdd(con_list_t* const this, const con_listType_t value)
{
	con_list_node_t* e = malloc(sizeof(con_list_node_t));
	e->value = value;
	e->next = NULL;

	if (con_listIsEmpty(this))
	{
		this->begin = e;
		this->end = e;
	}
	else
	{
		this->end->next = e;
		this->end = e;
	}
	this->size++;
}

char con_listRemove(con_list_t* const this, const con_listType_t value)
{
	if (con_listIsEmpty(this))
		return 0;

	con_list_node_t* it = this->begin;
	con_list_node_t* prev = NULL;
	do
	{
		if (it->value == value)
		{
			if (prev == NULL)
				this->begin = it->next;
			else
				prev->next = it->next;
			free(it);
			this->size--;
			return 1;
		}
		prev = it;
		it = it->next;
	} while (it != NULL);

	fprintf(stderr, "con_remove(): Element not found!\n");
	return 0;
}

con_listType_t con_listGet(const con_list_t* const this, long index)
{
	if (index >= con_listSize(this))
	{
		fprintf(stderr, "con_get(): Index out of bounce!\n");
		return INT_MIN;
	}

	int i = 0;
	con_list_node_t* it = this->begin;
	for (i = 0; i < index; i++)
		it = it->next;
	return it->value;
}

char con_listIsEmpty(const con_list_t* const this)
{
	if (!this->begin)
		return 1;
	else
		return 0;
}

long con_listSize(const con_list_t* const this)
{
	return this->size;
}

void con_listPrint(const con_list_t* const this)
{
	if (con_listIsEmpty(this))
	{
		printf("List is empty!\n");
		return;
	}
	con_list_node_t* it = this->begin;
	printf("List:");
	do
	{
		printf(" %d", it->value);
		it = it->next;
	} while (it != NULL);

	printf("\n");
}

void con_listFree(con_list_t* this)
{
	con_list_node_t* it = this->begin;
	con_list_node_t* toDel;
	while (it != NULL)
	{
		toDel = it;
		it = it->next;
		free(toDel);
	}
	free(this);
}
