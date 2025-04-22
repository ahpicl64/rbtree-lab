#include "rbtree.h"

#include <stdlib.h>

rbtree *new_rbtree(void) {
    rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
    // TODO: initialize struct if needed
    p->nil = malloc(sizeof(node_t));
    p->nil->color = RBTREE_BLACK;
    p->nil->left = p->nil;
    p->nil->right = p->nil;
    p->nil->parent = p->nil;

    p->root = p->nil;
    return p;
}

void free_node(rbtree *t, node_t *p){
    if(p == t->nil){
        return;
    }
    free_node(t, p->left);
    free_node(t, p->right);
    free(p);
}

void delete_rbtree(rbtree *t) {
    // TODO: reclaim the tree nodes's memory
    free_node(t, t->root);
    free(t->nil);
    free(t);
}

void bst_insert(rbtree *t, node_t *p){
    node_t *cur_node = t->root;
    node_t *parent_node = t->nil;
    while (cur_node != t->nil){
        parent_node = cur_node;
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

void left_rotate(rbtree *t, node_t *parent_node){
    node_t *child_node = parent_node->right;
    parent_node->right = child_node->left;
    if(child_node != t->nil){
        child_node->left->parent = parent_node;
    }

    // If the original parent was the tree root, set root to the child
    // otherwise update the childe_node pointer to grandparent's left or right 
    if(parent_node->parent == t->nil){
        t->root = child_node;
    } else if (parent_node == parent_node->parent->left){
        parent_node->parent->left = child_node;
    } else {
        parent_node->parent->right = child_node;
    }
    child_node->left = parent_node;
    parent_node->parent = child_node;
}

void right_rotate(rbtree *t, node_t *parent_node){
    node_t *child_node = parent_node->left;
    parent_node->left = child_node->right;
    if(child_node != t->nil){
        child_node->right->parent = parent_node;
    }
  
    // If the original parent was the tree root, set root to the child
    // otherwise update the childe_node pointer to grandparent's left or right 
    if(parent_node->parent == t->nil){
        t->root = child_node;
        child_node->parent = t->root;
    } else if (parent_node == parent_node->parent->left){
        parent_node->parent->left = child_node;
    } else {parent_node->parent->right = child_node;}
    child_node->left = parent_node;
    parent_node->parent = child_node;
}

void rb_insert_fix_up(rbtree *t, node_t *p){
    while (p->parent->color == RBTREE_RED && p->parent != t->nil){
        if (p->parent == p->parent->parent->left){      // parent's location is grandparent's left side
            // uncle's color is RBTREE_RED (Case 1)
            if (p->parent->parent->right->color == RBTREE_RED){   // recoloring
                p->parent->color = RBTREE_BLACK;
                p->parent->parent->right->color = RBTREE_BLACK;
                p->parent->parent->color = RBTREE_RED;
                rb_insert_fix_up(t, p->parent->parent);
            } else {  // uncle's color is RBTREE_BLACK
                if (p == p->parent->right){                 // Tree is L-R pattren (inner case) (Case 2)
                    p = p->parent;
                    left_rotate(t, p);
                    }                                           // Tree is L-L pattren (outer case) (Case 3)
                p->parent->color = RBTREE_BLACK;
                p->parent->parent->color = RBTREE_RED;
                right_rotate(t, p->parent->parent);
            }
        } else {                        // parent->right == p
            if (p->parent->parent->left->color == RBTREE_RED){   // recoloring
                p->parent->color = RBTREE_BLACK;
                p->parent->parent->left->color = RBTREE_BLACK;
                p->parent->parent->color = RBTREE_RED;
                rb_insert_fix_up(t, p->parent->parent);
            } else {  // uncle's color is RBTREE_BLACK
                if (p == p->parent->left){                 // Tree is L-R pattren (inner case) (Case 2)
                    p = p->parent;
                    right_rotate(t, p);
                }                                           // Tree is L-L pattren (outer case) (Case 3)
                p->parent->color = RBTREE_BLACK;
                p->parent->parent->color = RBTREE_RED;
                left_rotate(t, p->parent->parent);
            }
        }
    }
    t->root->color = RBTREE_BLACK;
}

node_t *rbtree_insert(rbtree *t, const key_t key) {
    // TODO: implement insert
    // 삽입 노드 초기화
    node_t *node = malloc(sizeof(node_t));
    node->key = key;
    node->left = t->nil;
    node->right = t->nil;
    node->parent = t->nil;
    node->color = RBTREE_RED;

  // do bst insertion
    bst_insert(t, node);
    rb_insert_fix_up(t, node);
    t->root->color = RBTREE_BLACK;
    return t->root;
}

node_t *rbtree_find(const rbtree *t, const key_t key) {
    // TODO: implement find
    node_t *cur = t->root;

    while(cur != t->nil){
        if(cur->key == key){
            return cur;
        }
        else if(cur->key < key){
            cur = cur->right;
        }
        else {cur = cur->left;}
    }
    
    return cur;
}
node_t *tree_minimum(const rbtree *t, node_t *p) {
    while (p->left != t->nil) {
        p = p->left;
    }
    return p;
}

node_t *rbtree_min(const rbtree *t) {
    // TODO: implement find
    return tree_minimum(t, t->root);
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


