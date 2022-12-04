#include <stdint.h>
#include <stdio.h>

#include "tests.h"
#include "list.h"
#include "solution.h"
#include "util.h"

void list_test( uint32_t max, uint32_t N )
{
  printf( "***-list test-***\n" );
// creating a sample list
  List_t* l = NULL;
  // filling the list
  for( uint32_t i = 1u; i <= max; i++ )
    list_add( &l, i );

  printf( "list before removing items:\n" );
  print_list( l );
  remove_every( l, N );
  printf( "list after removing items:\n" );
  print_list( l );

  // clearing
  list_clear( &l );
  printf( "***-end of test-***\n\n" );
}

void tree_height_test()
{
  printf( "***-tree test-***\n" );
//---create tree---//
  // do not check for memory allocation errors
  tree_node_t* root = alloc_node(); // <-- create your own tree here
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

  //---calc tree height---//
  int height = tree_height( root );
  printf( "tree height = %d\n", height );

  //---remove tree---//
  tree_clear_node( &root );
  root = NULL;
  printf( "***-end of test-***\n\n" );
}

void min_max_test( uint32_t value )
{
  printf( "***-min & max test-***\n" );
  //--print min and max values---//
  print_min_max( value );
  printf( "***-end of test-***\n\n" );
}

void word_count_test( const char* text )
{
  printf( "***-word count test-***\n" );

  List_t* lst = count_str( text ); // <-- input test string here

  //---list printing---//
  if( lst == NULL )
    {
      printf( "can't count words!\n" );
      return; // error
    }
  else
    {
      size_t sz = list_size( lst );
      printf( "items count: %zu\n", sz );
      List_t* ptr = lst;
      do
        {
          str_sz_t* pss = ( str_sz_t* )&ptr->payload;
          printf( "len = %u, count = %u\n", pss->key, pss->value );
        }
      while( ( ptr = ptr->next ) != NULL );

      //---clearing list---//
      list_clear( &lst );
      lst = NULL;
    }
  printf( "***-end of test-***\n\n" );
}

void primes_test( unsigned long N )
{
  printf( "***-primes test-***\n" );
  unsigned long* buf = calloc( N, sizeof( unsigned long ) );

  get_primes( N, buf );

  for( unsigned i = 0u; i < N; i++ )
    printf( "%u ", ( unsigned )buf[i] );
  printf( "\n" );
  free( buf );
  printf( "***-end of test-***\n\n" );
}
