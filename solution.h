#ifndef __SOLUTION_H_INCLUDED__
#define __SOLUTION_H_INCLUDED__

#include <stdlib.h>

#include "list.h"
#include "tree.h"

/**
 * \brief finds the first N prime numbers
 * and places them in the specified array
 * \param[in] N - required count of numbers
 * \param[out] buf - an array to write the numbers
 */
void get_primes( unsigned long N, unsigned long* buf );

/**
 * \brief removes every N-th item from the list
 * \param[in] head - the head of the list
 * \param[in] n - items number for removal
 */
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

/**
 * \brief calculates the height of a binary tree
 * \param[in] root - the root of a binary tree
 * \return height of a binary tree
 */
int tree_height( const tree_node_t* root );

#endif // __SOLUTION_H_INCLUDED__
