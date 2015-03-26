/**
 * Linked list for integers.
 *
 * \author cpieloth
 */

#ifndef CONTAINER_LIST_H_
#define CONTAINER_LIST_H_

#include <stddef.h> // size_t

typedef enum
{
    list_FALSE, list_TRUE
} list_bool_type;

typedef size_t list_size_type; //!< Type for index and size.

typedef int list_value_type; //!< Value type to be stored.

extern const list_value_type list_NO_VALUE; //!< Indicates if an error or no value is returned.

/**
 * Internal value wrapper.
 */
typedef struct _list_node
{
    list_value_type value;
    struct _list_node* next;
} list_node;

/**
 * Structure to hold a list.
 */
typedef struct
{
    list_node* begin;
    list_node* end;
    list_size_type size;
} list;

/**
 * Initializes a list instance.
 *
 * \param this A list structure.
 */
void list_init(list* const this);

/**
 * Appends an element at the list's end.
 *
 * \param this List instance.
 * \param value Value to append.
 */
void list_push_back(list* const this, const list_value_type value);

/**
 * Removes first element which is found with the given value.
 *
 * \param this List instance.
 * \param value value to delete
 * \return list_TRUE if element was found and removed, else list_FALSE.
 */
list_bool_type list_remove(list* const this, const list_value_type value);

/**
 * Gets the element at the defined position.
 *
 * \param this List instance.
 * \param index Postion in the list.
 * \return The value at the index or list_NO_VALUE.
 */
list_value_type list_at(const list* const this, list_size_type index);

/**
 * Check if the list is empty.
 *
 * \param this List instance.
 * \return list_TRUE if the given list is empty, else list_FALSE.
 */
list_bool_type list_empty(const list* const this);

/**
 * Get element count.
 *
 * \param this List instance.
 */
list_size_type list_size(const list* const this);

/**
 * Prints the list on stdout.
 *
 * \param this List instance.
 */
void list_print(const list* const this, const char* const prefix);

/**
 * Remove all entries from the list. Does not free the values!
 *
 * \param this List instance.
 */
void list_clear(list* const this);

#endif /* CONTAINER_LIST_H_ */
