#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "list.h"
#include "tree.h"

#pragma pack(push, 2)

typedef struct str_sz
{
  unsigned key   : 16;
  unsigned value : 16;
} str_sz_t;

#pragma pack(pop)

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
 * \brief searches the list of structures
 * by the key.
 * \param[in] head - a pointer to the head of the list
 * \param[in] key
 * \return List_t* pointer to the node if ok,
 * NULL otherwise
 */
List_t* find_by_key( const List_t* head, unsigned key );

//---------------------------------------------------//

int main()
{
  // we take into account punctuation marks as well as
  // all other visible printed characters
  const char*text = "That's one small step for a man, one giant leap for mankind";

  // do not check for memory allocation errors
  tree_node_t* root = alloc_node();
  /*
            * root
           / \
          *   *
         /    /\
        *    *  *
                 \
                  *
  */
  root->leftChild = alloc_node();
  root->rightChild = alloc_node();
  root->leftChild->leftChild = alloc_node();
  root->rightChild->leftChild = alloc_node();
  root->rightChild->rightChild = alloc_node();
  root->rightChild->rightChild->rightChild = alloc_node();
  int height = tree_height( root );
  printf( "tree height = %d\n", height );
  tree_clear_node( &root );
  root = NULL;
  List_t* lst = count_str( text );
  if( lst == NULL )
    {
      printf( "can't count words!\n" );
      return EXIT_FAILURE;
    }
  else
    {
      size_t sz = list_size( lst );
      printf( "items count: %u\n", sz );
      List_t* ptr = lst;
      do
        {
          str_sz_t* pss = ( str_sz_t* )&ptr->payload;
          printf( "len = %u, count = %u\n", pss->key, pss->value );
        }
      while( ( ptr = ptr->next ) != NULL );
      list_clear( &lst );
      lst = NULL;
      return EXIT_SUCCESS;
    }
  return EXIT_SUCCESS;
}


// List of str_sz_t structs!!!
List_t* find_by_key( const List_t* head, unsigned key )
{
  if( head == NULL )
    return NULL;
  List_t* ptr = head;
  do
    {
      str_sz_t* pair = ( str_sz_t* ) &ptr->payload;
      if( pair->key == key )
        return ptr;
    }
  while( ( ptr = ptr->next ) != NULL );
  return NULL;
}

List_t* count_str( const char* str )
{
  size_t len = strlen( str );
  if( str == NULL || len == 0u )
    return NULL;
  List_t* head = NULL;
  unsigned word_ctr = 0u;
  for( size_t i = 0u; i <= len; i++ )
    {
      if( isprint( str[i] ) && isgraph( str[i] ) )
        {
          word_ctr++;
          continue;
        }
      else
        {
          if( word_ctr == 0u )
            continue;
          str_sz_t ss;
          memset( &ss, 0, sizeof( str_sz_t ) );
          List_t* ptr = find_by_key( head, word_ctr );
          if( ptr == NULL )
            {
              ss.key   = word_ctr;
              ss.value = 1;
              uint32_t val  = 0;
              memcpy( &val, &ss, sizeof( str_sz_t ) );
              list_add( &head, val );
              word_ctr = 0u;
              continue;
            }
          else
            {
              str_sz_t* sptr = ( str_sz_t* )( &ptr->payload );
              sptr->value++;
              word_ctr = 0u;
              continue;
            }
        }
    }
  return head;
}


void print_min_max( uint32_t value )
{
  uint32_t max = 0u;
  uint32_t min = 0u;
  if( value > 0 )
    {
      unsigned ctr = 0u;
      const uint32_t bit = 1;
      for( unsigned i = 0u; i < sizeof( value ) * 8u; i++ )
        {
          if( value & ( bit << i ) ) ctr++;
        }
      for( unsigned i = 0u; i < ctr; i++ )
        {
          min |= bit << i;
          max |= bit << ( 31u - i );
        }
    }
  printf( "min = %u\nmax = %u\n", min, max );
}
