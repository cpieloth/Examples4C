#ifndef OO_CONCEPT_COUNTER_H_
#define OO_CONCEPT_COUNTER_H_

#include <stdbool.h>

typedef struct counter
{
    bool (*construct)(struct counter* const this);
    void (*destruct)(struct counter* const this);

    void (*increment)(struct counter* const this);
    size_t (*counter)(struct counter* const this);
    void* __data; // Bad: still indirect access to private attribute
} Counter;

Counter* init_counter(Counter* const this);
Counter* new_counter();
void delete_counter(Counter* const this);

#endif /* OO_CONCEPT_COUNTER_H_ */
