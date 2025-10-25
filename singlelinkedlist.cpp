#include<stdio.h>
#include<stdlib.h>
typedef struct linkedlist
{
	int data;
	struct linkedlist *next;
}node;
node *head=NULL;

int count_node()
{
	int count=0;
	node *ptr;
	ptr=head;
	while(ptr!=NULL)
	{
	count++;
	ptr=ptr->next;
	}
	return count;
}

void create()
{
	node *newnode,*ptr1;
	newnode=(node*)malloc(sizeof(node));
	printf("enter any number");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(head==NULL)
	{
	head=newnode;	
	}
	else
	{
	ptr1=head;
		while(ptr1->next!=NULL)
		{
			ptr1=ptr1->next;
		}
	ptr1->next=newnode;
	}
}

void insertbegin()
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	printf("enter any number");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(newnode==NULL)
	{
		head=newnode;
	}
	else
	{
	newnode->next=head;
	head=newnode;	
	}
}
void insertmiddle()
{
	int a,pos;
	node *ptr,*ptr1,*newnode;
	printf("enter position to insert");
	scanf("%d",&pos);
	if(pos==1)
	{
	insertbegin();	
	}
	else
	{
	a=count_node();
	printf("Count is %d",a);
	if(pos<=a)
		{
			newnode=(node*)malloc(sizeof(node));
		printf("enter any number");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		ptr=ptr1=head;
			for(int i=1;i<pos;i++)
			{
				ptr=ptr1;
				ptr1=ptr1->next;
			}
		newnode->next=ptr1;
		ptr->next=newnode;	
		}
		else
		{
			printf("wrong input\n");
		}
	}
}
void insertend()
{
	create();
}
void deletebegin()
{
	if(head==NULL)
	{
		printf("empty list");
	}
	else
	{
	node *ptr1;
	ptr1=head;
	head=ptr1->next;
	printf("Deletion done of %d",ptr1->data);
	free(ptr1);
	}
}
void deletemiddle()
{
	int pos,a;
	printf("enter position for deletion\n");
	scanf("%d",&pos);
		if(head==NULL)
	{
		printf("empty list");
	}
	else if(pos==1)
	{
		deletebegin();
	}
	else
	{
	a=count_node();
	printf("Count is %d\n",a);
	if(pos<=a)
		{
			node *ptr,*ptr1;
			ptr=ptr1=head;
			for(int i=1;i<pos;i++)
			{
				ptr=ptr1;
				ptr1=ptr1->next;
			}
		ptr->next=ptr1->next;
		printf("Deletion done of %d",ptr1->data);
		free(ptr1);
		}
	} 
}
void deleteend()
{
	node *ptr,*ptr1;
	if(head==NULL)
	{
		printf("empty list");
	}
	else
	{
		ptr=head;
		if(ptr->next==NULL)
		{
		printf("Deletion done of %d",ptr->data);
		free(ptr);
		head=NULL;
		}
		else
		{
			ptr=ptr1=head;
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
		int ch,ins,del;
		printf("\n1.Create\n2.Insert\n3.Delete\n4.Display\n5.Exit");
		printf("\nEnter choice");
		scanf("%d",& ch);
		switch(ch)
		{
			case 1:
				create();
			break;
			case 2:
				printf("\n1.Insert begin\n2.Insert middle\n3.Insert end");
				printf("\nenter choice for insertion");
				scanf("%d",&ins);
				switch(ins)
				{
					case 1:
						insertbegin();
					break;
					case 2:
						insertmiddle();
					break;
					case 3:
						insertend();
					break;
				}
			break;
			case 3:
				printf("\n1.Delete begin\n2.Delete middle\n3.Delete end");
				printf("\nenter choice for deletion");
				scanf("%d",&del);
				switch(del)
				{
					case 1:
						deletebegin();
					break;
					case 2:
						deletemiddle();
					break;
					case 3:
						deleteend();
					break;
				}
			break;
			case 4:
				display();
			break;
			case 5:
				exit(0);
			break;
			default:
				printf("\nwrong choice");	
		}
	}
}
