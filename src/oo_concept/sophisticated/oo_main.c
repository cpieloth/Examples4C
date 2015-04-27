/**
 * @file
 * @author cpieloth
 *
 * TODO documentation
 */

#include <stdio.h>
#include <stdlib.h>

#include "Counter.h"
#include "SpecialCounter.h"

int main()
{
    printf("Counter sophisticated\n");

    // Heap
    printf("\n");
    printf("Counter ... \n");

    Counter* ptr_counter = new_counter();
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

    // Heap
    printf("\n");
    printf("SpecialCounter ... \n");

    SpecialCounter* ptr_special_counter = new_special_counter();
    if (ptr_special_counter == NULL)
    {
        printf("Could not create special counter!");
        return EXIT_FAILURE;
    }

    ptr_special_counter->construct(ptr_special_counter);

    printf("SpecialCounter: %zu\n", ptr_special_counter->counter(ptr_special_counter));
    printf("SpecialCounter: %zu\n", ptr_special_counter->counter2(ptr_special_counter));

    ptr_special_counter->increment(ptr_special_counter);
    ptr_special_counter->increment2(ptr_special_counter);

    printf("SpecialCounter: %zu\n", ptr_special_counter->counter(ptr_special_counter));
    printf("SpecialCounter: %zu\n", ptr_special_counter->counter2(ptr_special_counter));

    delete_special_counter(ptr_special_counter);

    // TODO upper cast/downcast ...
    ptr_counter = (Counter*) ptr_special_counter;
    ptr_counter->increment(ptr_counter);
    printf("Counter casted: %zu\n", ptr_counter->counter(ptr_counter));

    return EXIT_SUCCESS;
}
