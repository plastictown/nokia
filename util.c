#include <stdio.h>

#include "util.h"

void print_list(List_t* head)
{
  if(head == NULL)
  {
    printf("list is empty\n");
    return;
  }
  List_t* ptr = head;
  do
  {
    printf(" %d", ptr->payload);
  }
  while((ptr = ptr->next) != NULL);
  printf("\n");
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
