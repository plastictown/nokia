#ifndef __UTIL_H_INCLUDED__
#define __UTIL_H_INCLUDED__

#include "list.h"

#pragma pack(push, 2)

// the structure that will be stored
// in the uint32_t type list
typedef struct str_sz
{
  unsigned key   : 16;
  unsigned value : 16;
} str_sz_t;

#pragma pack(pop)

void print_list( List_t* head );
List_t* find_by_key( List_t* head, unsigned key );

#endif // __UTIL_H_INCLUDED__
