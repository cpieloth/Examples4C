#ifndef OO_CONCEPT_SOPHISTICATED__SPECIALCOUNTER_H_
#define OO_CONCEPT_SOPHISTICATED__SPECIALCOUNTER_H_

#include "SpecialCounter.h"
#include "Counter.h"

#undef GET_CLASS_DATA
#define GET_CLASS_DATA(this) ((_SpecialCounterData*)this)

typedef struct _special_counter_data
{
    SpecialCounter class;
    Counter* super;
    size_t count2;
} _SpecialCounterData;

static void SpecialCounter_construct(SpecialCounter* const this);
static void SpecialCounter_destruct(SpecialCounter* const this);

static void SpecialCounter_increment(SpecialCounter* const this);
static size_t SpecialCounter_counter(SpecialCounter* const this);

static void SpecialCounter_increment2(SpecialCounter* const this);
static size_t SpecialCounter_counter2(SpecialCounter* const this);

#endif /* OO_CONCEPT_SOPHISTICATED__SPECIALCOUNTER_H_ */
