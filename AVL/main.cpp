#include <iostream>
#include "tree.h"

int main(){
  ArbolBin A;
  A.insert(10);
  A.insert(1);
  A.insert(2);
  A.insert(12);
  printf("Recorrido preorder:\n");
  A.preOrder();
  printf("Recorrido inorder:\n");
  A.inOrder();
  printf("Recorrido postorder:\n");
  A.postOrder();

  return 0;
}
