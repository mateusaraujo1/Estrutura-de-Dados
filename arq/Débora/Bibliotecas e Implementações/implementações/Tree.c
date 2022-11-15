#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "Tree.h"

struct Tree{
  void *value;
  Tree *left;
  Tree *right;
};

Tree *Tree_create(void *value, Tree *left, Tree *right){
  Tree *tree = NULL;
  if(value){
    tree = malloc(sizeof(Tree));
    tree->value = value;
    tree->left = left;
    tree->right = right;
  }
  return tree;
}

void Tree_destroy(Tree *tree){
  if(tree){
    Tree_destroy(tree->left);
    tree->left = NULL;
    Tree_destroy(tree->right);
    tree->right = NULL;
    free(tree);
  }
}

void *Tree_getValue(Tree *tree){
  if(tree)
    return tree->value;
  else
    return NULL;
}

Tree *Tree_getLeft(Tree *tree){
  if(tree)
    return tree->left;
  else
    return NULL;
}
Tree *Tree_getRight(Tree *tree){
  if(tree)
    return tree->right;
  else
    return NULL;
}

void Tree_setValue(Tree *tree, void *value){
  if(tree && value)
    tree->value = value;
}

void Tree_setLeft(Tree *tree, void *value){
  if(tree && value)
    tree->left = Tree_create(value, NULL, NULL);
}

void Tree_setRight(Tree *tree, void *value){
  if(tree && value)
    tree->right = Tree_create(value, NULL, NULL);
}

void Tree_print(Tree *tree, void (*print)(void *)){
  if(tree){
    if(tree->value){
      printf("<");
      print(tree->value);
      Tree_print(tree->left, print);
      Tree_print(tree->right, print);
      printf(">");
    }
  }
  else
    printf("<>");
}

void Tree_calcular(Tree *tree, int *resultado, int *tam, int *left, int *right){
  if(tree){
    if(tree->value){
      Tree_calcular(tree->left, resultado, tam, left, right);
      Tree_calcular(tree->right, resultado, tam, left, right);
      char *c = (char*)tree->value;
      if(*c == '+' || *c == '-' || *c == '*'){
        if(isdigit(*(char*)tree->left->value)){
          *left = atoi((char*)tree->left->value);
          tree->left->value = left;
        }
        if(isdigit(*(char*)tree->right->value)){
          *right = atoi((char*)tree->right->value);
          tree->right->value = right;
        }
        if(*c == '+'){
          resultado[*tam] = *(int*)tree->left->value + *(int*)tree->right->value;
          tree->value = &resultado[*tam];
          --*tam;
        }
        else if(*c == '-'){
          resultado[*tam] = *(int*)tree->left->value - *(int*)tree->right->value;
          tree->value = &resultado[*tam];
          --*tam;
        }
        else if(*c == '*'){
          resultado[*tam] = *(int*)tree->left->value * *(int*)tree->right->value;
          tree->value = &resultado[*tam];
          --*tam;
        }
        free(tree->left);
        free(tree->right);
        tree->left = NULL;
        tree->right = NULL;
      }
    }
  }
}

int Tree_alt(Tree *tree){
  int l, r;
  if(tree == NULL) {
    return 0;
  }
  else{
    l = 1 + Tree_alt(tree->left);
    r = 1 + Tree_alt(tree->right);
    if(l > r)
      return l;
    else
      return r;
  }
}

void *Tree_getParent(Tree *tree, void *value, int (*comparStr)(const void *, const void *)){
  if(tree && value){
    if(tree->value){
      if(comparStr(tree->value, value) == 0){
        printf("Entrou\n");
        return tree->parent;
      }
      else{
       Tree_getParent(tree->left, value, comparStr);
       Tree_getParent(tree->right, value, comparStr);
      }
    }
  }
}
