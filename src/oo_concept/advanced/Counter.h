#ifndef OO_CONCEPT_COUNTER_H_
#define OO_CONCEPT_COUNTER_H_

typedef struct counter
{
    void (*construct)(struct counter* const this);
    void (*destruct)(struct counter* const this);

    void (*increment)(struct counter* const this);
    size_t (*counter)(struct counter* const this);

    size_t __count; // Bad: direct access to private attribute
} Counter;

Counter* init_counter(Counter* const this);
Counter* new_counter();
void delete_counter(Counter* const this);

void Counter_construct(Counter* const this);
void Counter_destruct(Counter* const this);

void Counter_increment(Counter* const this);
size_t Counter_counter(Counter* const this);

#endif /* OO_CONCEPT_COUNTER_H_ */
