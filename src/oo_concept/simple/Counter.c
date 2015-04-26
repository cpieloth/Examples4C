#include <assert.h>
#include <stdio.h>

#include "Counter.h"

#define TRACE printf("%s() called!\n", __func__)

void Counter_construct(Counter* const this)
{
    assert(this != NULL);
    TRACE;
    this->__count = 0;
}

void Counter_destruct(Counter* const this)
{
    assert(this != NULL);
    TRACE;
    this->__count = 0;
}

void Counter_increment(Counter* const this)
{
    assert(this != NULL);
    TRACE;
    ++this->__count;
}

size_t Counter_counter(Counter* const this)
{
    assert(this != NULL);
    return this->__count;
}
