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

    // Counter_construct(ptr_counter); // Good: not possible

    if (ptr_counter->construct(ptr_counter) == false)
    {
        printf("Could not construct counter!");
        return EXIT_FAILURE;
    }
    // printf("counter.__counter=%zu\n", counter.__count); // Good: no direct access to private variables
    // counter.__data = 0; // Bad: private variable still accessible

    printf("Counter: %zu\n", ptr_counter->counter(ptr_counter));

    // Counter_increment(&counter); // Good: no (OO-)static class methods
    ptr_counter->increment(ptr_counter); // Good: object methods
    ptr_counter->increment(ptr_counter);

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

    if (ptr_counter->construct(ptr_counter) == false)
    {
        printf("Could not construct counter!");
        delete_counter(ptr_counter);
        return EXIT_FAILURE;
    }

    printf("Counter: %zu\n", ptr_counter->counter(ptr_counter));

    ptr_counter->increment(ptr_counter);
    ptr_counter->increment(ptr_counter);

    printf("Counter: %zu\n", ptr_counter->counter(ptr_counter));

    delete_counter(ptr_counter);

    return EXIT_SUCCESS;
}
