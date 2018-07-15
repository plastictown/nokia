#ifndef __LIST_H_INCLUDED__
#define __LIST_H_INCLUDED__

#include <stdint.h>
#include <stdlib.h>

typedef struct List
{
  struct List* next;
  uint32_t payload;
} List_t;

List_t* list_get_last( List_t* head );
List_t* list_add( List_t** phead, uint32_t value );
int list_remove_last( List_t** phead );
size_t list_size( List_t* head );
void list_clear( List_t** phead );
const List_t* list_find( List_t* head, uint32_t value );

#endif // __LIST_H_INCLUDED__
