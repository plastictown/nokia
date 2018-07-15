#ifndef __SOLUTION_H_INCLUDED__
#define __SOLUTION_H_INCLUDED__

#include <stdlib.h>

#include "list.h"
#include "tree.h"

void remove_every( List_t* head, size_t n );

/**
 * \brief prints the largest and smallest
 * numbers of the same count of binary 1
 * as in the specified value.
 * \param[in] value - source number
 */
void print_min_max( uint32_t value );

/**
 * \brief counts the number of words of
 * different lengths
 * \param[in] str - null-terminated string
 * \return - list of str_sz_t structures
 * \remarks - the returned list must be
 * released manually
 */
List_t* count_str( const char* str );

int tree_height( const tree_node_t* root );

#endif // __SOLUTION_H_INCLUDED__
