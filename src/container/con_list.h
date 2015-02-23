/**
 * Linked list for integers.
 *
 * \author cpieloth
 */

#ifndef CON_LIST_H_
#define CON_LIST_H_

/**
 * Defines the type of the list.
 */
typedef int con_listType_t;

/**
 * Internal value wrapper.
 */
typedef struct con_list_node
{
	con_listType_t value;
	struct con_list_node* next;
} con_list_node_t;

/**
 * Structure to hold a list.
 */
typedef struct con_list
{
	con_list_node_t* begin;
	con_list_node_t* end;
	long size;
} con_list_t;

/**
 * Creates a new list.
 *
 * \return a list structure.
 */
con_list_t* con_listCreate();

/**
 * Appends an element to the list.
 *
 * \param this list to append to.
 * \param value value to append.
 * \return value wrapper.
 */
void con_listAdd(con_list_t* const this, const con_listType_t value);

/**
 * Removes first element which is found with the given value.
 *
 * \param this list to remove from.
 * \param value value to delete
 * \return 1 if element was found, else 0.
 */
char con_listRemove(con_list_t* const this, const con_listType_t value);

/**
 * Gets the element at the defined position.
 *
 * \param this list to get from.
 * \param index postion in the list.
 * \return the value or NULL/NaN/MinimumOfType if position >= size
 */
con_listType_t con_listGet(const con_list_t* const this, long index);

/**
 * Check if the list is empty.
 *
 * \param this list to check.
 * \return 1 if the given list is empty, else 0.
 */
char con_listIsEmpty(const con_list_t* const this);

/**
 * Get element count.
 *
 * \param this list.
 */
long con_listSize(const con_list_t* const this);

/**
 * Prints the list on stdo.
 *
 * \param this list to be printed.
 */
void con_listPrint(const con_list_t* const this);

/**
 * Frees all created data.
 *
 * \param this	list to free.
 */
void con_listFree(con_list_t* this);

#endif /* CON_LIST_H_ */
