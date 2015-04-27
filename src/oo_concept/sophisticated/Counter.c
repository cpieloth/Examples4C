#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "_Counter.h"

#define TRACE printf("%s() called!\n", __func__)

Counter* new_counter()
{
    _CounterData* instance = (_CounterData*) malloc(sizeof(_CounterData));
    if (instance == NULL)
    {
        return NULL;
    }
    instance->class.construct = &Counter_construct;
    instance->class.destruct = &Counter_destruct;
    instance->class.increment = &Counter_increment;
    instance->class.counter = &Counter_counter;
    return (Counter*) instance;
}

void delete_counter(Counter* const this)
{
    if (this == NULL)
    {
        return;
    }
    Counter_destruct(this);
    free(this);
}

static void Counter_construct(Counter* const this)
{
    assert(this != NULL);
    TRACE;
    GET_CLASS_DATA(this)->count = 0;
}

static void Counter_destruct(Counter* const this)
{
    assert(this != NULL);
    TRACE;
}

static void Counter_increment(Counter* const this)
{
    assert(this != NULL);
    TRACE;
    _CounterData* const data = GET_CLASS_DATA(this);
    ++data->count;
}

static size_t Counter_counter(Counter* const this)
{
    assert(this != NULL);
    return GET_CLASS_DATA(this)->count;
}
