#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "_SpecialCounter.h"

#define TRACE printf("%s() called!\n", __func__)

SpecialCounter* new_special_counter()
{
    _SpecialCounterData* instance = (_SpecialCounterData*) malloc(sizeof(_SpecialCounterData));
    if (instance == NULL)
    {
        return NULL;
    }
    instance->super = new_counter();
    // check error;
    instance->class.increment = &SpecialCounter_increment;
    instance->class.counter = &SpecialCounter_counter;

    instance->class.construct = &SpecialCounter_construct;
    instance->class.destruct = &SpecialCounter_destruct;
    instance->class.increment2 = &SpecialCounter_increment2;
    instance->class.counter2 = &SpecialCounter_counter2;

    return (SpecialCounter*) instance;
}

void delete_special_counter(SpecialCounter* const this)
{
    if (this == NULL)
    {
        return;
    }
    delete_counter(GET_CLASS_DATA(this)->super);
    SpecialCounter_destruct(this);
    free(this);
}

static void SpecialCounter_construct(SpecialCounter* const this)
{
    assert(this != NULL);
    TRACE;
    _SpecialCounterData* data = GET_CLASS_DATA(this);
    data->super->construct(data->super);
    data->count = 10;
}

static void SpecialCounter_destruct(SpecialCounter* const this)
{
    assert(this != NULL);
    TRACE;
    _SpecialCounterData* data = GET_CLASS_DATA(this);
    data->super->destruct(data->super);
}

static void SpecialCounter_increment(SpecialCounter* const this)
{
    _SpecialCounterData* data = GET_CLASS_DATA(this);
    return data->super->increment(data->super);
}

static size_t SpecialCounter_counter(SpecialCounter* const this)
{
    _SpecialCounterData* data = GET_CLASS_DATA(this);
    return data->super->counter(data->super);
}

static void SpecialCounter_increment2(SpecialCounter* const this)
{
    assert(this != NULL);
    TRACE;
    _SpecialCounterData* const data = GET_CLASS_DATA(this);
    ++data->count;
}

static size_t SpecialCounter_counter2(SpecialCounter* const this)
{
    assert(this != NULL);
    return GET_CLASS_DATA(this)->count;
}
