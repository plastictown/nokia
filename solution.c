#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "list.h"
#include "tree.h"
#include "solution.h"
#include "util.h"

void remove_every(List_t* head, size_t n)
{
  if (head == NULL)
    return;
  if (n < 2u)
    return;
  if (head->next == NULL)
    return;
  size_t ctr = 1;
  List_t* ptr = head->next;
  List_t* prev = head;

  while (ptr->next != NULL)
  {
    ctr++;
    if (ctr%n == 0u)
    {
      prev->next = ptr->next;
      free(ptr);
      ptr = prev->next;
      continue;
    }
    prev = ptr;
    ptr = ptr->next;
  }
  ctr++;
  if (ctr%n == 0u)
  {
    prev->next = NULL;
    free(ptr);
    ptr = NULL;
  }
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
              uint32_t val  = 0u;
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

int tree_height( const tree_node_t* root )
{
  if( root == NULL )
    return 0;
  int l = 0, r = 0;
  if( root->leftChild != NULL )
    {
      l = tree_height( root->leftChild );
    }
  else
    {
      l = -1;
    }
  if( root->rightChild != NULL )
    {
      r = tree_height( root->rightChild );
    }
  else
    {
      r = -1;
    }
  int max = l > r ? l : r;
  return max + 1;
}
