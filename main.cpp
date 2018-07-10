#include <iostream>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

//using namespace std;

typedef struct List
{
  struct List* next;
  int payload;
} List_t;

void list_init( List_t* head )
{
  if( head != NULL )
    {
      head->next = NULL;
      head->payload = 0;
    }
}

List_t* list_get_last( List_t* head )
{
  if( head == NULL )
    return NULL;
  List_t* cur = head;
  while( cur->next != NULL )
    cur = cur->next;
  return cur;
}

List_t* list_add( List_t* head, int value )
{
  if( head == NULL )
    return NULL;
  List_t* last = list_get_last( head );
  last->next = ( List_t* )calloc( 1, sizeof( List_t ) );
  if( last->next == NULL )
    return NULL;
  List_t* cur = last->next;
  cur->next = NULL;
  cur->payload = value;
  return cur;
}


int list_remove_last( List_t* head )
{
  if( head == NULL ) return 0;
  if( head->next == NULL )
    return 0;
  List_t* cur = head;
  while( cur->next->next != NULL )
    cur = cur->next;
  free( cur->next );
  cur->next = NULL;
  return 1;
}

size_t list_size( List_t* head )
{
  if( head == NULL )
    return 0u;
  size_t ret = 1;
  List_t* cur = head;
  while( ( cur = cur->next ) != NULL )
    ret++;
  return ret;
}

void list_clear( List_t* head )
{
  if( head == NULL )
    return;
  while( list_remove_last( head ) );
}

/**
  * @param [in] n - should be great than 1
  */
void remove_every( List_t* head, size_t n )
{
  if( head == NULL || n < 2 ) return;
  // only one element in the list
  List_t* cur = head;
  size_t ctr  = 1;
  while( cur->next != NULL )
    {
      List_t* prev = cur;
      cur = cur->next;
      if( ctr % n == 0 )
        {
          prev->next = cur->next;
          free( cur );
        }
      ctr++;
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

int main()
{
  List_t l;
  list_init( &l );
  for( int i = 1; i < 100; i++ )
    list_add( &l, i );
  std::cout << list_size( &l ) << std::endl;
  remove_every( &l, 10 );
  std::cout << list_size( &l ) << std::endl;
  list_clear( &l );
  std::cout << list_size( &l ) << std::endl;
  print_min_max( ( uint32_t ) - 7 );
  return 0;
}
