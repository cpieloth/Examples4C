#ifndef OO_CONCEPT__COUNTER_H_
#define OO_CONCEPT__COUNTER_H_

#include "Counter.h"

typedef struct _counter_data
{
    size_t count;
} _CounterData;

static bool Counter_construct(Counter* const this);
static void Counter_destruct(Counter* const this);

static void Counter_increment(Counter* const this);
static size_t Counter_counter(Counter* const this);

#endif /* OO_CONCEPT__COUNTER_H_ */
