#ifndef __TREE_H_INCLUDED__
#define __TREE_H_INCLUDED__

typedef struct TreeNode
{
  struct TreeNode* leftChild;
  struct TreeNode* rightChild;
} tree_node_t;

tree_node_t* alloc_node();
void tree_clear_node( tree_node_t** pnode );
#endif // __TREE_H_INCLUDED__
