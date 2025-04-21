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

  // do bst insertion
  bst_insert(t, node);



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

void left_rotate(rbtree *t, node_t *parent_node){
  node_t *child_node = parent_node->right;
  parent_node->right = child_node->left;
  if(child_node != t->nil){
    child_node->left->parent = parent_node;
  }

  // 기존 부모 노드가 root였는지, 아니라면 기존 부모의 왼쪽 또는 오른쪽 부모인지
  if(parent_node->parent == t->nil){
    t->root = child_node;
  } else if (parent_node == parent_node->parent->left){
    parent_node->parent->left = child_node;
  } else {parent_node->parent->right = child_node;}
  child_node->left = parent_node;
  parent_node->parent = child_node;
}

void right_rotate(rbtree *t, node_t *parent_node){
  node_t *child_node = parent_node->left;
  parent_node->left = child_node->right;
  if(child_node != t->nil){
    child_node->right->parent = parent_node;
  }
  
  // 기존 부모 노드가 root였는지, 아니라면 기존 부모의 왼쪽 또는 오른쪽 부모인지
  if(parent_node->parent == t->nil){
    t->root = child_node;
  } else if (parent_node == parent_node->parent->left){
    parent_node->parent->left = child_node;
  } else {parent_node->parent->right = child_node;}
  child_node->left = parent_node;
  parent_node->parent = child_node;
}