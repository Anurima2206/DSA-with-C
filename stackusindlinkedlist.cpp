#include<stdio.h>
#include<stdlib.h>
typedef struct linkedlist
{
	int data;
	struct linkedlist *next; 
}node;
node *top;

void create()
{
top=NULL;
}

void push(int no)
{
	node *newnode,*temp;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=no;
	newnode->next=NULL;
	if(top==NULL)
	{
		top=newnode;
	}
	else
	{
	temp=top;
	while(temp->next!=NULL)	
	{
		temp=temp->next;	
	}
	temp->next=newnode;
	}
	printf("insertion done of %d\n",newnode->data);
}

void pop()
{
	node *ptr1,*ptr;
	if(top==NULL)
	{
		printf("stack underflow\n");
	}
	else
	{
	ptr=ptr1=top;
	while(ptr1->next!=NULL)
	{
		ptr=ptr1;
		ptr1=ptr1->next;
	}
	printf("Deletion done of %d",ptr1->data);
	free(ptr1);
	ptr->next=NULL;
	}
}

void display()
{
	node *ptr;
	if(top==NULL)
	{
		printf("stack underflow\n");
	}
	else
	{
		ptr=top;
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
}

int main()
{
	create();
	while(1)
	{
		int ch;
		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
		printf("\nEnter choice");
		scanf("%d",& ch);
		switch(ch)
		{
			case 1:
				int n1;
				printf("enter any number");
				scanf("%d",&n1);
				push(n1);
			break;
			case 2:
				pop();
			break;
			case 3:
				display();
			break;
			case 4:
				exit(0);
			break;
			default:
				printf("wrong choice");
		}
	}
}
