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
    printf("Counter advanced\n");

    // Stack
    printf("\n");
    printf("Instances on stack ... \n");

    Counter counter;
    Counter* ptr_counter = init_counter(&counter);

    ptr_counter->construct(ptr_counter);

    printf("counter.__counter=%zu\n", counter.__count); // Bad: access to private variable
    printf("Counter: %zu\n", ptr_counter->counter(ptr_counter));

    Counter_increment(&counter); // Bad: (OO-)static class method
    ptr_counter->increment(ptr_counter); // Good: object methods

    printf("Counter: %zu\n", ptr_counter->counter(ptr_counter));

    ptr_counter->destruct(ptr_counter);

    printf("Counter: %zu\n", ptr_counter->counter(ptr_counter));

    // Heap
    printf("\n");
    printf("Instances on heap ... \n");

    ptr_counter = new_counter();
    if (ptr_counter == NULL)
    {
        printf("Could not create counter!");
        return EXIT_FAILURE;
    }
    ptr_counter->construct(ptr_counter);

    printf("Counter: %zu\n", ptr_counter->counter(ptr_counter));

    ptr_counter->increment(ptr_counter);
    ptr_counter->increment(ptr_counter);

    printf("Counter: %zu\n", ptr_counter->counter(ptr_counter));

    delete_counter(ptr_counter);

    return EXIT_SUCCESS;
}
