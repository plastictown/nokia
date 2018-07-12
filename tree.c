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

int tree_height( const tree_node_t* root )
{
  if( root == NULL )
    return 0;
  int l = 0, r = 0;
  if( root->leftChild != NULL )
    {
      l = tree_height( root->leftChild );
    }
  else
    {
      l = -1;
    }
  if( root->rightChild != NULL )
    {
      r = tree_height( root->rightChild );
    }
  else
    {
      r = -1;
    }
  int max = l > r ? l : r;
  return max + 1;
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
