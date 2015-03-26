/**
 * Test run for rra implementation.
 *
 * \author	executor
 * \return	EXIT_SUCCESS
 */

#define TEST_OFF
#ifdef TEST_ON

#include <stdio.h>
#include <stdlib.h>

#include "con_rra.h"

int main(void)
{
    printf("RRA TEST\n");

    con_rra_t* rra = con_rraCreate(4);
    long i;
    for (i = 0; i < 2 * con_rraSize(rra) + 2; i++)
    {
        con_rraPut(rra, i);
        printf("get(%ld): %d (expected %ld)\n", i, con_rraGet(rra, i), i);
    }

    con_rraPrint(rra);

    con_rraSet(rra, con_rraSize(rra) + 1, 42);
    con_rraPrint(rra);
    printf("get(con_rraSize(rra) + 1): %d (expected 42)\n", con_rraGet(rra, con_rraSize(rra) + 1));
    printf("get(1): %d (expected 42)\n", con_rraGet(rra, 1));

    con_rraFree(rra);

    return EXIT_SUCCESS;
}

#endif /* TEST_ON */
