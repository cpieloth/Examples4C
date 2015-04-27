#ifndef OO_CONCEPT_SOPHISTICATED_SPECIALCOUNTER_H_
#define OO_CONCEPT_SOPHISTICATED_SPECIALCOUNTER_H_

typedef struct special_counter
{
    void (*construct)(struct special_counter* const this);
    void (*destruct)(struct special_counter* const this);

    void (*increment)(struct special_counter* const this);
    size_t (*counter)(struct special_counter* const this);

    void (*increment2)(struct special_counter* const this);
    size_t (*counter2)(struct special_counter* const this);
} SpecialCounter;

SpecialCounter* new_special_counter();
void delete_special_counter(SpecialCounter* const this);

#endif /* OO_CONCEPT_SOPHISTICATED_SPECIALCOUNTER_H_ */
