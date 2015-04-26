/**
 * @file
 * @author cpieloth
 *
 * TODO documentation
 */

#include <stdio.h>
#include <stdlib.h>

#include "Counter.h"

int main()
{
    printf("Counter simple\n");
    printf("\n");

    Counter counter;
    Counter_construct(&counter);

    printf("counter.__counter=%zu\n", counter.__count); // Bad: access to private variable
    printf("Counter: %zu\n", Counter_counter(&counter));

    Counter_increment(&counter); // Bad: (OO-)static class methods
    Counter_increment(&counter);

    printf("Counter: %zu\n", Counter_counter(&counter));

    Counter_destruct(&counter);

    printf("Counter: %zu\n", Counter_counter(&counter));

    return EXIT_SUCCESS;
}
