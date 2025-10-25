#include<stdio.h>
#include<stdlib.h>
typedef struct linkedlist
{
	int data;
	struct linkedlist *next,*prev;
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
	node *newnode,*tmp;
	newnode=(node*)malloc(sizeof(node));
	printf("enter any number");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	if(head==NULL)
	{
		head=tmp=newnode;
	}
	else
	{
		tmp=head;
		while(tmp->next!=NULL)
		{
			tmp=tmp->next;
		}
	tmp->next=newnode;
	newnode->prev=tmp;
	}
}

void insertbegin()
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	printf("enter any number");
	scanf("%d",&newnode->data);
	newnode->next=NULL;	
	newnode->prev=NULL;	
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		newnode->next=head;
		head->prev=newnode;
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
		newnode->prev=NULL;
		ptr=head;
		for(int i=2;i<pos;i++)
			{
				ptr=ptr->next;
			}
		newnode->next=ptr->next;
		ptr->next->prev=newnode;
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
		printf("list empty");
	}
	else
	{
		node *temp;
		temp=head;
		head=temp->next;
		head->prev=NULL;
		free(temp);
		printf("Deletion done of %d",temp->data);
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
		node *tmp,*tmp1;
		tmp=tmp1=head;
		for(int i=1;i<pos;i++)
			{
				tmp=tmp1;
				tmp1=tmp1->next;
			}
		tmp->next=tmp1->next;
		tmp1->next->prev=tmp;
		printf("Deletion done of %d",tmp1->data);
		free(tmp1);
		}
		else
		{
		printf("wrong input\n");
		}
	}
}

void deleteend()
{
	
	node *tmp,*tmp1;
	if(head==NULL)
	{
		printf("empty list");
	}
	else
	{
		tmp=head;
		if(tmp->next==NULL)
		{
		printf("Deletion done of %d",tmp->data);
		free(tmp);
		head=NULL;
		}
		else
		{
			tmp=tmp1=head;
			while(tmp1->next!=NULL)
			{
				tmp=tmp1;
				tmp1=tmp1->next;
			}
		printf("Deletion done of %d",tmp1->data);
		free(tmp1);
		tmp->next=NULL;	
		}
	}
}

void displayforward()
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

void displaybackward()
{
	node *ptr;
	if(head==NULL)
	{
		printf("Linked List is empty\n");
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->prev;
		}
	}
}

int main()
{
	while(1)
	{
		int ch,ins,del,dis;
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
				printf("\n1.Display forward\n2.Display backward");
				printf("\nenter choice for display");
				scanf("%d",&dis);
				switch(dis)
				{
					case 1:
						displayforward();
					break;
					case 2:
						displaybackward();
					break;
				}
			break;
			case 5:
				exit(0);
			break;
			default:
				printf("\nwrong choice");	
		}
	}
}
