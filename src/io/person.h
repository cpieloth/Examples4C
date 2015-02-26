#ifndef IO_PERSON_H_
#define IO_PERSON_H_

typedef struct
{
	char* forename;
	char* surname;
	int year_of_birth;
} Person;

Person* psn_create(char* forename, char* surname, int year_of_birth);

void psn_free(Person* const p);

char* psn_to_string(const Person* const p);

#endif /* IO_PERSON_H_ */
