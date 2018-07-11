#ifndef __LIST_H_INCLUDED__
#define __LIST_H_INCLUDED__

#include <stdlib.h>

typedef struct List
{
  struct List* next;
  int payload;
} List_t;

void list_init( List_t* head );
List_t* list_get_last( List_t* head );
List_t* list_add( List_t* head, int value );
int list_remove_last( List_t* head );
size_t list_size( List_t* head );
void list_clear( List_t* head );
void remove_every( List_t* head, size_t n );

#endif // __LIST_H_INCLUDED__
