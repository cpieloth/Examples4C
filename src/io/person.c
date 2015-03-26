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
    char* const yob = itoa(p->year_of_birth);
    const char sep[] = ", ";

    size_t len = 1; // \0
    len += strlen(p->forename);
    len += strlen(sep);
    len += strlen(p->surname);
    len += strlen(sep);
    len += strlen(yob);

    char* const str_p = malloc(len);
    str_p[0] = '\0';
    strcat(str_p, p->forename);
    strcat(str_p, sep);
    strcat(str_p, p->surname);
    strcat(str_p, sep);
    strcat(str_p, yob);

    free(yob);
    return str_p;
}
