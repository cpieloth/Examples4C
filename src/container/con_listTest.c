#define TEST_OFF
#ifdef TEST_ON

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "con_list.h"

/**
 * Test run for list implementation.
 *
 * \author	executor
 * \return	EXIT_SUCCESS
 */
int main()
{
	printf("LIST TEST\n");

	con_list_t* l = con_listCreate();

	printf("isEmpty(): %d (expected 1)\n", con_listIsEmpty(l));
	printf("get(0): %d (expected %d)\n", con_listGet(l, 0), INT_MIN); // may change to NaN

	int i;
	for (i = 0; i < 5; i++)
	{
		con_listAdd(l, i);
		printf("get(%d): %d (expected %d)\n", i, con_listGet(l, i), i);
	}
	con_listPrint(l);

	printf("remove(-1): %d (expected 0)\n", con_listRemove(l, -1));

	printf("remove(0): %d (expected 1)\n", con_listRemove(l, 0));
	printf("get(0): %d (expected 1)\n", con_listGet(l, 0));

	printf("remove(2): %d (expected 1)\n", con_listRemove(l, 2));
	printf("get(2): %d (expected 4)\n", con_listGet(l, 2));

	printf("remove(4): %d (expected 1)\n", con_listRemove(l, 4));
	printf("get(1): %d (expected 3)\n", con_listGet(l, 1));

	printf("remove(99): %d (expected 0)\n", con_listRemove(l, 99));
	printf("remove(3): %d (expected 1)\n", con_listRemove(l, 3));
	printf("remove(1): %d (expected 1)\n", con_listRemove(l, 1));
	printf("remove(99): %d (expected 0)\n", con_listRemove(l, 99));
	printf("isEmpty(): %d (expected 1)\n", con_listIsEmpty(l));

	for (i = 0; i < 3; i++)
	{
		con_listAdd(l, i);
		printf("get(%d): %d (expected %d)\n", i, con_listGet(l, i), i);
	}
	con_listPrint(l);

	con_listFree(l);

	return EXIT_SUCCESS;
}

#endif /* TEST_ON */
