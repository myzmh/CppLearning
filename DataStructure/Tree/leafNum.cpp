#include <iostream>
using namespace std;

typedef char ElemType;
typedef struct BitNode
{
  ElemType data;
  struct BitNode *lchild, *rchild;
} BitNode, *BitTree;

void CreateBitTree(BitNode &BT, char *&str)
{
  char ch;
  ch = *str++;
  if (ch == '#')
    BT = NULL;
  else
  {
    BT = new node;
    BT->data = ch;
    CreateBitTree(BT->lchild, str);
    CreateBitTree(BT->rchild, str);
  }
}

void Empty(BitNode BT)
{
  BT = NULL;
}

bool IsEmpty(BitTree BT)
{
  if (BT == NULL)
    return true;
  else
    return false;
}

BitTree CreateBT(datatype v, BitTree ltree, BitTree rtree)
{
  BitTree root;
  root = new node;
  root->data = v;
  root->lchild = ltree;
  root->rchild = rtree;
  return root;
}
BitTree Lchild(BitTree BT)
{
  return BT->lchild;
}
BitTree Rchild(BitTree BT)
{
  return BT->rchild;
}
datatype Data(BitTree BT)
{
  return BT->data;
}
void visit(datatype dt)
{
  cout << dt;
}
void PreOrder(BitTree BT)
{
  if (!IsEmpty(BT))
  {
    visit(Data(BT));
    PreOrder(Lchild(BT));
    PreOrder(Rchild(BT));
  }
}
void InOrder(BitTree BT)
{
  if (!IsEmpty(BT))
  {
    PreOrder(Lchild(BT));
    visit(Data(BT));
    PreOrder(Rchild(BT));
  }
}

void PostOrder(BitTree BT)
{
  if (!IsEmpty(BT))
  {
    PreOrder(Lchild(BT));
    PreOrder(Rchild(BT));
    visit(Data(BT));
  }
}
int leafnum(BitTree BT)
{
  static int count = 0;
  if (BT->lchild == NULL && BT->rchild == NULL)
    return ++count;
  else
  {
    leafnum(Lchild(BT));
    leafnum(Rchild(BT));
  }
}

int main()
{
  BitTree BT = NULL;
  char *str = "ab##c###def##g##h#ij##k#l";
  CreateBitTree(BT, str);
  cout << "Leave Number is:" << leafnum(BT) << endl;
}