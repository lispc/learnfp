#include "stdio.h"
#include "stdlib.h"
typedef struct _node
{
	int v;
	struct _node* next;
}node;
node* list;
void append_to_list(node* tail,int* pos,int num)
{

	while(num--)
	{
		tail->next=(node*)malloc(sizeof (node));
		tail=tail->next;
		tail->v=*pos++;
	}
	tail->next=0;//
}
void show_list(node* head)
{
	node* p=head;
	while(p)
	{
		printf("%d\n",p->v);
		p=p->next;
	}
}
node* _rev_list(node*old,node*new)
{
	if(!old)
		return new;
	node* temp=(node*)malloc(sizeof(node));
	temp->next=new;
	temp->v=old->v;
	return _rev_list(old->next,temp);
}
node* rev_list(node*list)
{
	return _rev_list(list,0);
}
int main()
{
	int vars[]={1,2,3,4,5,6};
	list=malloc(sizeof(node));
	append_to_list(list,vars,6);
	//node* p=rev(list);
	show_list(list->next);
	node* newlist=rev_list(list->next);
	show_list(newlist);
}
