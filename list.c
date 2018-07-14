#include <stdlib.h>
#include <stdint.h>
#include "list.h"

List_t* list_add(List_t** phead, uint32_t value)
{
  if (phead == NULL)
    return NULL;
  if (*phead == NULL)
  {
    *phead = (List_t*)calloc(1, sizeof(List_t));
    (*phead)->next = NULL;
    (*phead)->payload = value;
    return (*phead);
  }
  else
  {
    List_t* last = list_get_last(*phead);
    if (last == NULL)
      return NULL;
    last->next = (List_t*)calloc(1, sizeof(List_t));
    last->next->next = NULL;
    last->next->payload = value;
    return last->next;
  }
  return NULL;
}

List_t* list_get_last(List_t* head)
{
  if (head == NULL)
    return NULL;
  List_t* ptr = head;
  while (ptr->next != NULL)
    ptr = ptr->next;
  return ptr;
}

int list_remove_last(List_t** phead)
{
  if (phead == NULL)
    return 0;
  List_t* head = *phead;
  if (head == NULL)
    return 0;
  if (head->next == NULL)
  {
    free(head);
    *phead = NULL;
    return 0;
  }
  List_t* ptr = head;
  List_t* prev = NULL;
  while (ptr->next != NULL)
  {
    prev = ptr;
    ptr = ptr->next;
  }
  free(ptr);
  prev->next = NULL;
  return 1;
}

void list_clear(List_t** phead)
{
  if (phead == NULL)
    return;
  while (list_remove_last(phead));
}

size_t list_size(List_t* head)
{
  if (head == NULL)
    return 0u;
  size_t sz = 0u;
  List_t* ptr = head;
  do
  {
    sz++;
  } while ((ptr = ptr->next) != NULL);
  return sz;
}

const List_t* list_find(const List_t* head, uint32_t value)
{
  if (head == NULL)
    return NULL;
  List_t* ptr = head;
  do
  {
    if (ptr->payload == value)
      return ptr;
  } while ((ptr = ptr->next) != NULL);
  return NULL;
}

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
}
