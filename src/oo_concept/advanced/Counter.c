#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "_Counter.h"

#define TRACE printf("%s() called!\n", __func__)

Counter* init_counter(Counter* const this)
{
    assert(this != NULL);
    this->construct = &Counter_construct;
    this->destruct = &Counter_destruct;
    this->increment = &Counter_increment;
    this->counter = &Counter_counter;
    return this;
}

Counter* new_counter()
{
    Counter* instance = (Counter*) malloc(sizeof(Counter));
    if (instance == NULL)
    {
        return NULL;
    }
    init_counter(instance);
    return instance;
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

static bool Counter_construct(Counter* const this)
{
    assert(this != NULL);
    TRACE;
    this->__data = malloc(sizeof(_CounterData));
    if (this->__data)
    {
        return true;
    }
    else
    {
        return false;
    }
}

static void Counter_destruct(Counter* const this)
{
    assert(this != NULL);
    TRACE;
    free(this->__data);
}

static void Counter_increment(Counter* const this)
{
    assert(this != NULL);
    assert(this->__data != NULL);
    TRACE;
    _CounterData* const data = (_CounterData*) this->__data;
    ++data->count;
}

static size_t Counter_counter(Counter* const this)
{
    assert(this != NULL);
    assert(this->__data != NULL);
    _CounterData* const data = (_CounterData*) this->__data;
    return data->count;
}
