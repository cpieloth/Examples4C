#ifndef OO_CONCEPT__COUNTER_H_
#define OO_CONCEPT__COUNTER_H_

#include "Counter.h"

#undef GET_CLASS_DATA
#define GET_CLASS_DATA(this) ((_CounterData*)this)

typedef struct _counter_data
{
    Counter class;
    size_t count;
} _CounterData;

static void Counter_construct(Counter* const this);
static void Counter_destruct(Counter* const this);

static void Counter_increment(Counter* const this);
static size_t Counter_counter(Counter* const this);

#endif /* OO_CONCEPT__COUNTER_H_ */
