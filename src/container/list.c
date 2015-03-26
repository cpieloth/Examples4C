#include <limits.h> // INT_MIN
#include <stdlib.h> // malloc
#include <stdio.h> // fprintf, printf

#include "list.h"

const list_value_type list_NO_VALUE = INT_MIN;

void list_init(list* const this)
{
    this->begin = NULL;
    this->end = NULL;
    this->size = 0;
}

void list_push_back(list* const this, const list_value_type value)
{
    list_node* e = malloc(sizeof(list_node));
    e->value = value;
    e->next = NULL;

    if (list_empty(this) == list_TRUE)
    {
        this->begin = e;
        this->end = e;
    }
    else
    {
        this->end->next = e;
        this->end = e;
    }
    ++this->size;
}

list_bool_type list_remove(list* const this, const list_value_type value)
{
    if (list_empty(this) == list_TRUE)
    {
        return list_FALSE;
    }

    list_node* it = this->begin;
    list_node* prev = NULL;
    do
    {
        if (it->value == value)
        {
            if (prev == NULL)
                this->begin = it->next;
            else
                prev->next = it->next;
            free(it);
            --this->size;
            return list_TRUE;
        }
        prev = it;
        it = it->next;
    } while (it != NULL);

    return list_FALSE;
}

list_value_type list_at(const list* const this, list_size_type index)
{
    if (index >= list_size(this))
    {
        fprintf(stderr, "%s(): Index out of bounce!\n", __func__);
        return list_NO_VALUE;
    }

    list_node* it = this->begin;
    for (list_size_type i = 0; i < index; ++i)
    {
        it = it->next;
    }
    return it->value;
}

list_bool_type list_empty(const list* const this)
{
    if (!this->begin)
        return list_TRUE;
    else
        return list_FALSE;
}

list_size_type list_size(const list* const this)
{
    return this->size;
}

void list_print(const list* const this, const char* const prefix)
{
    if (list_empty(this) == list_TRUE)
    {
        printf("%s[]\n", prefix);
        return;
    }
    list_node* it = this->begin;
    printf("%s[", prefix);
    do
    {
        printf(" %d,", it->value);
        it = it->next;
    } while (it != NULL);

    printf("]\n");
}

void list_clear(list* const this)
{
    list_node* it = this->begin;
    list_node* toDel;
    while (it != NULL)
    {
        toDel = it;
        it = it->next;
        free(toDel);
        --this->size;
    }

    this->begin = NULL;
    this->end = NULL;
}
