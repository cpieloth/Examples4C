#include <math.h>
#include <stdlib.h>
#include <stdio.h> // sprintf
#include <string.h>

#include "person.h"

static char* itoa(int num)
{
	// log10(num) gives the number of digits; + 1 for the null terminator
	const int size = log10(num) + 1;
	char* str = malloc(size);
	sprintf(str, "%d", num);
	return str;
}

Person* psn_create(char* forename, char* surname, int year_of_birth)
{
	Person* p = malloc(sizeof(Person));
	p->forename = strdup(forename);
	p->surname = strdup(surname);
	p->year_of_birth = year_of_birth;
	return p;
}

void psn_free(Person* const p)
{
	free(p->forename);
	free(p->surname);
	free(p);
}

char* psn_to_string(const Person* const p)
{
	char* yob = itoa(p->year_of_birth);
	size_t len = 1;
	len += strlen(p->forename);
	len += 2; // ", "
	len += strlen(p->surname);
	len += 2; // ", "
	len += strlen(yob);

	char sep[] = ", ";
	char* str_p = malloc(len + 1);
	strcat(str_p, p->forename);
	strcat(str_p, sep);
	strcat(str_p, p->surname);
	strcat(str_p, sep);
	strcat(str_p, yob);

	free(yob);
	return str_p;
}
