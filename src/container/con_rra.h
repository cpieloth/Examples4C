/**
 * Round robin array (rra).
 *
 * \@author	executor
 */

#ifndef CON_RRD_H_
#define CON_RRA_H_

/**
 * Defines the type of the array.
 */
typedef int con_rraType_t;

/**
 * Structure for the container.
 */
typedef struct con_rra
{
    con_rraType_t* values;
    long pos;
    long size;
} con_rra_t;

/**
 * Creates a new round robin array.
 *
 * \param size	Size of the array
 * \return a rra structure.
 */
con_rra_t* con_rraCreate(const long size);

/**
 * Puts a new value in the array, other value will may be overwritten.
 *
 * \param this	rra to put into.
 * \param value	value to put.
 */
long con_rraPut(con_rra_t* const this, const con_rraType_t value);

/**
 * Gets a value from the array.
 *
 * \param this	rra to get from.
 * \param pos	position in the array (pos % size)
 * \return
 */
con_rraType_t con_rraGet(const con_rra_t* const this, long pos);

/**
 * Sets a value in the array.
 *
 * \param this	rra to set into.
 * \param pos	position in the array (pos % size)
 * \param value	value to set.
 */
long con_rraSet(con_rra_t* const this, long pos, const con_rraType_t value);

/**
 * Get array size.
 *
 * \param this rra.
 */
long con_rraSize(const con_rra_t* const this);

/**
 * Prints the rra on stdo.
 *
 * \param this raa to be printed.
 */
void con_rraPrint(const con_rra_t* const this);

/**
 * Frees all created data.
 *
 * \param this	rra to free.
 */
void con_rraFree(con_rra_t* this);

#endif /* CON_RRA_H_ */
