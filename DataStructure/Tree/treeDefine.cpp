#include <iostream>
using namespace std;

typedef char elemType;
struct BitNode {
  elemType data;
  BitNode *leftChild, *rightChild;
} BitNode, *BitTree;

void CreateBitTree(&BT, *&str){
  char ch = *str++;
  if (ch == '#')
    BT = NULL;
  else
  {
    BT = new BitNode;
    BT -> data = ch;
    CreateBitTree(BT -> leftChild, str);
    CreateBitTree(BT -> rightChild, str);
  }
}

int main()
{
  BitNode BitTree;
  char *str = "ab##cde#f#g#h"
  CreateBitTree(BT, str)
  
  return 0;
}
