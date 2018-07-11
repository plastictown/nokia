#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "list.h"

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
  if( head == NULL || n < 2u ) return;
  // only one element in the list
  List_t* cur = head;
  size_t ctr  = 1u;
  while( cur->next != NULL )
    {
      List_t* prev = cur;
      cur = cur->next;
      if( ctr % n == 0u )
        {
          prev->next = cur->next;
          free( cur );
          cur = prev;
        }
      ctr++;
    }
}
