#include <iostream>
using namespace std;
struct node
{
	int date;
	node *next;
};
void add(node *head,node *end,int a);
void build(node *head,node *end,int a);
int main(int argc, char** argv)
{
	node *head=NULL,*end=NULL;
	for(int i=0;;i++)
	{
		add(head,end,i);
	}
	return 0;
}
void build(node *head,node *end,int a)//建立一个以head为头指针，以end为尾指针的链表，第一个数据为a 
{
	node *p;
	p=new node;
	p->date=a;
	p->next=NULL;
	head=p;
	end=p;
}
void add(node *head,node *end,int a)//在一个以head为头指针，以end为尾指针的链表末尾加入数据a 
{
	if(head->next==NULL)
	{
		build(head,end,a);
	}
	else
	{
		node *p;
		p=new node;
		p->date=a;
		p->next=NULL;
		end->next=p;
		end=p;
	}
}
