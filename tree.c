#include <stdlib.h>
#include "tree.h"

tree_node_t* alloc_node()
{
  tree_node_t* node = (tree_node_t*) calloc(1, sizeof(tree_node_t));
  if(node != NULL)
  {
    node->leftChild  = NULL;
    node->rightChild = NULL;
  }
  return node;
}
