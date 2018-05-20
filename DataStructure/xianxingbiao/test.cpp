// 写一个算法合并两个已排序的线性表。
// 要求：1、定义线性表节点的结构，并定义节点的型和位置的型。
//       2、定义线性表的基本操作
//       3、在1，2的基础上，完成本题。
//       4、在main函数中进行测试：先构建两个有序的线性表，然后合并这两个线性表。

#include<iostream>
using namespace std;
typedef int Elementtype;
struct celltype{
	Elementtype element;
	celltype *next;
};
typedef celltype *LIST;
typedef celltype *position;
position End(LIST L)
{
	position p;
	p=L;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	return p;
}
void Insert(Elementtype x,position p)
{
	position q;
	q=new celltype;
	q->element=x;
	q->next=p->next;
	p->next=q;
}
void Delete(position p)//删除p的下一个节点 
{
	position q;
	if(p->next!=NULL)
	{
		q=p->next;
		p->next=q->next;
		delete q;
	}
	
}
position Locate(Elementtype x,LIST L)
{
	position p;
	p=L;
	while(p->next!=NULL)
	{
		if(p->next->element==x)
		return p;
		else
		p=p->next;
	}
	return p;
}
position MakeNull(LIST&L)
{
	L=new celltype;
	L->next=NULL;
	return L; 
}
void merge(LIST&L,LIST&L1,LIST&L2)
{
	position p,p1,p2;
	for(p1=L1;p1;p1=p1->next)
	{
		p=new celltype;
		p->element=p1->element;
		if(L==0)
		{
			L=p;
			p2=p;
		}
		else
		{
			p2->next=p;
			p2=p;
		}
	}
	p2->next=NULL;
	for(p1=L2;p1;p1=p1->next)
	{
		p=new celltype;
		p->element=p1->element;
		if(L==0)
		{
			L=p;
			p2=p;
		}
		else
		{
			p2->next=p;
			p2=p;
		}
	}
	p2->next=NULL;
}
void Read(LIST &L)
{
	position p1,p2;
//	p1=new celltype;
	cout<<"请输入数据以-1结束"<<endl;
	for(;;)
	{
		p1=new celltype;
		cin>>p1->element;
		if(p1->element==-1)
			break;
		if(L==0)
		{
			L=p1;
			p2=p1;	
		}	
		else
		{
			p2->next=p1;
			p2=p1;
		} 
		
	}
	p2->next=NULL;
}
void write(LIST&L)
{
	position p;
	p=L;
	for(;p;p=p->next)
	{
		cout<<p->element<<"\t";
		
	}
	cout<<endl;
}
int main()
{
	LIST L=NULL,L1=NULL,L2=NULL;
	Read(L1);
	write(L1);
	Read(L2);
	write(L2);
	merge(L,L1,L2);
	write(L);
}

