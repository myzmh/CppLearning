// 用递归方法写一个算法，求二叉树的叶子结点数int leafnum(BTREE T)。
// 要求：
// 1、	定义二叉树的抽象数据类型和型BTREE，并定义基本操作。
// 2、	编写函数leafnum(BTREE T)，返回树T的叶子节点的个数。
// 在主函数中，构建一个二叉树，并验证所编写的算法。


#include <iostream>
using namespace std;
typedef char datatype;
struct node
{
  node *lchild;
  datatype data;
  node *rchild;
};
typedef node *BTREE;
void CreateBTREE(BTREE &BT, char *&str) // 先根输入树
{
  char ch;
  ch = *str++;
  if (ch == '#')
    BT = NULL;
  else
  {
    BT = new node;
    BT->data = ch;
    CreateBTREE(BT->lchild, str);
    CreateBTREE(BT->rchild, str);
  }
}
void Empty(BTREE BT)
{
  BT = NULL;
}
bool IsEmpty(BTREE BT) // 判断是否为空
{
  if (BT == NULL)
    return true;
  else
    return false;
}
BTREE CreateBT(datatype v, BTREE ltree, BTREE rtree) // 用左右子树建立二叉树
{
  BTREE root;
  root = new node;
  root->data = v;
  root->lchild = ltree;
  root->rchild = rtree;
  return root;
}
BTREE Lchild(BTREE BT) // 返回左子树
{
  return BT->lchild;
}
BTREE Rchild(BTREE BT) // 返回右子树 
{
    return BT->rchild;
}
datatype Data(BTREE BT) // 返回节点元素值
{
  return BT->data;
}
void visit(datatype dt)
{
  cout << dt;
}
void PreOrder(BTREE BT) // 先根顺序遍历
{
  if (!IsEmpty(BT))
  {
    visit(Data(BT));
    PreOrder(Lchild(BT));
    PreOrder(Rchild(BT));
  }
}
void InOrder(BTREE BT) // 中根顺序遍历
{
  if (!IsEmpty(BT))
  {
    PreOrder(Lchild(BT));
    visit(Data(BT));
    PreOrder(Rchild(BT));
  }
}
void PostOrder(BTREE BT) // 后根顺序遍历
{
  if (!IsEmpty(BT))
  {
    PreOrder(Lchild(BT));
    PreOrder(Rchild(BT));
    visit(Data(BT));
  }
}
int count2(BTREE BT)
{
  if (BT == NULL)
    return 0;
  else
  {
    if ((BT->lchild) && (BT->rchild))
      return 1 + count2(Lchild(BT)) + count2(Rchild(BT));
    if ((BT->lchild) && (BT->rchild == NULL))
      return count2(Lchild(BT));
    if ((BT->lchild == NULL) && (BT->rchild))
      return count2(Rchild(BT));
  }
}
int leafnum(BTREE BT)
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
  BTREE BT = NULL;
  char *str = (char*)"abc##d##ef##g##";
  CreateBTREE(BT, str);
  cout << "度为 2 的节点的个数 :" << count2(BT) << endl;
  cout << "叶子节点个数： " << leafnum(BT) << endl;
}