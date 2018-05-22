// 写一个算法合并两个线性表。
// 要求：1、定义线性表节点的结构，并定义节点的型和位置的型。
//       2、定义线性表的基本操作
//       3、在1，2的基础上，完成本题。
//       4、在main函数中进行测试：先构建两个有序的线性表，然后合并这两个线性表。

#include<iostream>
using namespace std;

typedef int elementType;

struct cellType{
	elementType element;
	cellType *next;
};

typedef cellType *position;
typedef cellType *LIST;

position End(LIST L){
	position q;
	q = L;
	while(q->next != NULL){
		q = q->next;
	}
	return q;
}

void Insert(elementType x, position p){
	position q = new cellType;
	q->element = x;
	q->next = p->next;
	p->next = q;
}

// 删除节点 p 的下一个元素
void Delete(position p){
	if(p->next != NULL){
		position q = p->next;
		p->next = q->next;
		delete q;
	}
}

// 返回元素值为 x 的第一个节点
position Local(elementType x, LIST L){
	position p;
	p = L;
	while(p->next != NULL){
		if(p->element == x){
			return p;
		}
		else{
			p = p->next;
		}
	}
	return p;
}

position MakeNull(LIST &L){
	L = new cellType;
	L->next = NULL;
	return L;
}

void merge(LIST &L, LIST &L1, LIST &L2){
	position p, p1, p2;
	for(p1 = L1; p1; p1 = p1->next){
		p = new cellType;
		p->element = p1->element;
		if(L == 0){
			L = p;
			p2 = p;
		}
		else{
			p2->next = p;
			p2 = p;
		}
	}
	p2->next = NULL;

	for(p1 = L2; p1; p1 = p1->next){
		p = new cellType;
		p->element = p1->element;
		if( L == 0){
			 L = p;
			 p2 = p;
		}
		else{
			p2->next = p;
			p2 = p;
		}
	}
	p2->next = NULL;
}

// 从键盘读取用户输入
void read(LIST &L){
	position p1, p2;
	cout << "Enter the Data or -1 to end:" << endl;
	for(;;){
		p1 = new cellType;
		cin >> p1->element;
		if(p1->element == -1){
			break;
		}
		if(L == 0){
			L = p1;
			p2 = p1;
		}
		else{
			p2->next = p1;
			p2 = p1;
		}
	}
	p2->next = NULL;
}

void write(LIST &L){
	position p = L;
	for(; p ; p = p->next){
		cout << p->element << '\t';
	}
	cout << endl;
}

int main(){
	LIST L = NULL, L1 = NULL, L2 = NULL;
	read(L1);
	write(L1);
	read(L2);
	write(L2);
	merge(L, L1, L2);
	write(L);
	return 0;
}