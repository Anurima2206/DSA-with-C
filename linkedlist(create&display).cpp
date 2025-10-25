#include<stdio.h>
#include<stdlib.h>
typedef struct linkedlist
{
	int data;
	struct linkedlist *next;
}node;
node *head=NULL;

void create()
{
	node *ptr,*ptr1;
	ptr=(node*)malloc(sizeof(node));
	printf("enter any number");
	scanf("%d",&ptr->data);
	ptr->next=NULL;
	if(head==NULL)
	{
	head=ptr;	
	}
	else
	{
	ptr1=head;
		while(ptr1->next!=NULL)
		{
			ptr1=ptr1->next;
		}
	ptr1->next=ptr;
	}
}
void display()
{
	node *ptr;
	if(head==NULL)
	{
		printf("Linked List is empty\n");
	}
	else
	{
		ptr=head;
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
}
int main()
{
	while(1)
	{
		int ch;
		printf("\n1.Create\n2.Display\n3.Exit");
		printf("\nEnter choice");
		scanf("%d",& ch);
		switch(ch)
		{
			case 1:
				create();
			break;
			case 2:
				display();
			break;
			case 3:
				exit(0);
			break;
			default:
				printf("\nwrong choice");
		}
	}
}

