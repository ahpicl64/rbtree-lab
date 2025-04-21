#include "rbtree.h"

#include <stdlib.h>

rbtree *new_rbtree(void) {
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
  // TODO: initialize struct if needed
  p->nil = malloc(sizeof (node_t));
  p->nil->color = RBTREE_BLACK;
  p->nil->left = p->nil;
  p->nil->right = p->nil;
  p->nil->parent_node = p->nil;

  p->root = p->nil;
  return p;
}

void delete_rbtree(rbtree *t) {
  // TODO: reclaim the tree nodes's memory
  free(t);
}

node_t *rbtree_insert(rbtree *t, const key_t key) {
  // TODO: implement insert
  // 삽입 노드 초기화
  node = malloc(sizeof(node_t));
  node->key = key
  node->left = t->nil;
  node->right = t->nil;
  node->parent = t->nil;
  node->color = red;

  bst_insert(t, node);\


  return t->root;
}

node_t *rbtree_find(const rbtree *t, const key_t key) {
  // TODO: implement find
  return t->root;
}

node_t *rbtree_min(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

node_t *rbtree_max(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

int rbtree_erase(rbtree *t, node_t *p) {
  // TODO: implement erase
  return 0;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
  // TODO: implement to_array
  return 0;
}

void bst_insert(rbtree *t, node_t *p){
  node_t *cur_node = t->root;
  node_t *parent_node = t->nil;
  while (cur_node != nil){
    parent_node = cur_node
    if (p->key < cur_node->key){
      cur_node = cur_node->left;
    } else {
      cur_node = cur_node->right;
    }
  }
  p->parent = parent_node;
  if (parent_node == t->nil){
    t->root = p;
  } else if (p->key < parent_node->key){
    parent_node->left = p;
  } else {
    parent_node->right = p;
  }
  return;
}

void rb_insert_fix_up(rbtree *t, node_t *p){

}