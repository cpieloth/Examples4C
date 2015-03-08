/**
 * Example for Linux' list from sys/queue.h
 * \see http://linux.die.net/man/3/queue
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>

typedef int list_value_type; //!< Optional: Value type to be stored in your list.

/**
 * Abbreviation for struct list_entry
 */
typedef struct list_entry
{
	list_value_type value;
	LIST_ENTRY(list_entry) entries;
} list_entry_t;

/**
 * Type definition for your list and abbreviation for your LIST_HEAD.
 *
 * \param listhead Name could be anything, but unique in file.
 * \param list_entry Struct of your list entry.
 */
typedef LIST_HEAD(listhead, list_entry) list_t;

int main()
{
	list_t my_list;
	LIST_INIT(&my_list);

	list_entry_t *e, *e_after;
	e = malloc(sizeof(list_entry_t));
	e->value = 1;
	e_after = e;
	LIST_INSERT_HEAD(&my_list, e, entries);

	e = malloc(sizeof(list_entry_t));
	e->value = 2;
	LIST_INSERT_HEAD(&my_list, e, entries);

	e = malloc(sizeof(list_entry_t));
	e->value = 3;
	LIST_INSERT_AFTER(e_after, e, entries);

	printf("for-loop:\n");
	for (list_entry_t* e_for = LIST_FIRST(&my_list); e_for != NULL; e_for = LIST_NEXT(e_for, entries))
	{
		printf("%d\n", e_for->value);
	}

	printf("LIST_FOREACH:\n");
	LIST_FOREACH(e, &my_list, entries)
	{
		printf("%d\n", e->value);
	}

	printf("while-loop:\n");
	while (!LIST_EMPTY(&my_list))
	{
		e = LIST_FIRST(&my_list);
		printf("%d\n", e->value);
		LIST_REMOVE(e, entries);
		free(e); // Do not forget to free the list entries!
	}

	if (LIST_EMPTY(&my_list))
	{
		printf("List is empty!\n");
	}
	else
	{
		printf("List is NOT empty!\n");
	}

	return EXIT_SUCCESS;
}
