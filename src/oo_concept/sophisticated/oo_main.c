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

    // Counter
    printf("\n");
    printf("Counter ...\n");
    {
        Counter* counter = new_counter();
        if (counter == NULL)
        {
            printf("Could not create counter!");
            return EXIT_FAILURE;
        }

        counter->construct(counter);

        printf("Counter: %zu\n", counter->counter(counter));

        counter->increment(counter);
        counter->increment(counter);

        printf("Counter: %zu\n", counter->counter(counter));

        delete_counter(counter);
    }
    // Special Counter
    printf("\n");
    printf("SpecialCounter ...\n");
    {
        SpecialCounter* special_counter = new_special_counter();
        if (special_counter == NULL)
        {
            printf("Could not create special counter!");
            return EXIT_FAILURE;
        }

        special_counter->construct(special_counter);

        printf("SpecialCounter: %zu\n", special_counter->counter(special_counter));
        printf("SpecialCounter: %zu\n", special_counter->counter2(special_counter));

        special_counter->increment(special_counter);
        special_counter->increment2(special_counter);

        printf("SpecialCounter: %zu\n", special_counter->counter(special_counter));
        printf("SpecialCounter: %zu\n", special_counter->counter2(special_counter));

        delete_special_counter(special_counter);

    }
    // Up/Down cast
    printf("\n");
    printf("Up/Down cast ...\n");
    {
        SpecialCounter* special_counter = new_special_counter();
        if (special_counter == NULL)
        {
            printf("Could not create special counter!");
            return EXIT_FAILURE;
        }
        special_counter->construct(special_counter);

        Counter* counter = upcast_special_counter(special_counter);
        printf("Counter (upcasted): %zu\n", counter->counter(counter));
        // printf("Counter (upcasted): %zu\n", counter->counter2(counter)); // no member anymore!
        printf("SpecialCounter: %zu\n", special_counter->counter2(special_counter));

        counter->increment(counter);
        // counter->increment2(counter); // no member anymore!
        printf("Counter (upcasted): %zu\n", counter->counter(counter));
        // printf("Counter (upcasted): %zu\n", counter->counter2(counter)); // no member anymore!

        // counter->increment(counter);
        special_counter->increment(special_counter);
        printf("Counter (upcasted): %zu\n", counter->counter(counter));
        printf("SpecialCounter: %zu\n", special_counter->counter(special_counter));

        SpecialCounter* special_counter_dc = downcast_special_counter(counter);
        printf("Counter (upcasted): %zu\n", counter->counter(counter));
        printf("SpecialCounter (downcasted): %zu\n", special_counter_dc->counter2(special_counter_dc));

        if (special_counter != special_counter_dc)
        {
            printf("Original pointer and downcasted pointer are not equal!\n");
        }
    }

    return EXIT_SUCCESS;
}
