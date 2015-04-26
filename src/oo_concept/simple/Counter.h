#ifndef OO_CONCEPT_COUNTER_H_
#define OO_CONCEPT_COUNTER_H_

typedef struct
{
    size_t __count; // Bad: direct access to private attribute
} Counter;

void Counter_construct(Counter* const this);
void Counter_destruct(Counter* const this);

void Counter_increment(Counter* const this);
size_t Counter_counter(Counter* const this);

#endif /* OO_CONCEPT_COUNTER_H_ */
