#include <stdlib.h>

#include "tree.h"

tree_node_t* alloc_node()
{
  tree_node_t* node = ( tree_node_t* ) calloc( 1, sizeof( tree_node_t ) );
  if( node != NULL )
    {
      node->leftChild  = NULL;
      node->rightChild = NULL;
    }
  return node;
}

void tree_clear_node( tree_node_t** ppnode )
{
  if( ppnode == NULL )
    return;
  tree_node_t* pnode = *ppnode;
  if( pnode == NULL )
    return;
  if( pnode->leftChild != NULL )
    {
      tree_clear_node( &pnode->leftChild );
    }
  if( pnode->rightChild != NULL )
    {
      tree_clear_node( &pnode->rightChild );
    }
  free( pnode );
  *ppnode = NULL;
}
