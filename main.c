#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#include "list.h"
#include "tree.h"

void error(const char* text)
{
  write(fileno(stderr), text, strlen(text));
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

//---------------------------------------------------//



int main()
{
  tree_node_t* head = alloc_node();
  if(head == NULL)
  {
    error("can't allocate tree_node_t");
    return EXIT_FAILURE;
  }

  free(head);
  head = NULL;

  return EXIT_SUCCESS;
}
