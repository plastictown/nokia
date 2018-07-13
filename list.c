#include <stdlib.h>
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
  List_t* ptr = head;
  while( ptr->next != NULL )
    ptr = ptr->next;
  return ptr;
}

List_t* list_add( List_t* head, int value )
{
  if( head == NULL )
    return NULL;
  List_t* last = list_get_last( head );
  last->next = ( List_t* )calloc( 1, sizeof( List_t ) );
  if( last->next == NULL )
    return NULL;
  List_t* ptr = last->next;
  ptr->next = NULL;
  ptr->payload = value;
  return ptr;
}

int list_remove_last( List_t* head )
{
  if( head == NULL ) return 0;
  if( head->next == NULL )
    return 0;
  List_t* ptr = head;
  while( ptr->next->next != NULL )
    ptr = ptr->next;
  free( ptr->next );
  ptr->next = NULL;
  return 1;
}

size_t list_size( List_t* head )
{
  if( head == NULL )
    return 0u;
  size_t ret = 1;
  List_t* ptr = head;
  while( ( ptr = ptr->next ) != NULL )
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
  List_t* ptr = head;
  size_t ctr  = 1u;
  while( ptr->next != NULL )
    {
      List_t* prev = ptr;
      ptr = ptr->next;
      if( ctr % n == 0u )
        {
          prev->next = ptr->next;
          free( ptr );
          ptr = prev;
        }
      ctr++;
    }
}

const List_t* list_find(const List_t* head, int value)
{
  if(head == NULL)
    return NULL;
  List_t* ptr = head;
  do
  {
    if(ptr->payload == value)
      return ptr;
  }
  while((ptr = ptr->next) != NULL);
  
  return NULL;
}
