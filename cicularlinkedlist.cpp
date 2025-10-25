#include<stdio.h>
#include<stdlib.h>
typedef struct linkedlist
{
	int data;
	struct linkedlist *next;
}node;
node *head=NULL;
node *tail=NULL;

int count_node()
{
	int count=0;
	node *tmp;
	tmp=head;
	while(tmp!=tail)
	{
	count++;
	tmp=tmp->next;
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
	if(head==NULL)
	{
		head=newnode;	
		tail=newnode;	
	}
	else
	{
		tmp=head;
		while(tmp->next!=head)
		{
			tmp=tmp->next;
		}
		tmp->next=newnode;
		tail=newnode;
	}
	tail->next=head;
}
void insertbegin()
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	printf("enter any number");
	scanf("%d",&newnode->data);
	newnode->next=NULL;	
	if(head==NULL)
	{
		head=newnode;
		tail=newnode;
	}
	else
	{
		newnode->next=head;
		head=newnode;
	}
	tail->next=head;
}
void insertmiddle()
{
	int a,pos;
	node *tmp,*tmp1,*newnode;
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
			tmp=tmp1=head;
			for(int i=1;i<pos;i++)
			{
				tmp=tmp1;
				tmp1=tmp->next;
			}
		newnode->next=tmp1;
		tmp->next=newnode;	
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
	if(head==tail && head->next==head)
	{
		printf("Deletion done of %d",head->data);
		free(head);
		head=NULL;
		tail=NULL;
	}
	else
	{
	node *tmp;
	tmp=head;
	head=tmp->next;
	printf("Deletion done of %d",tmp->data);
	free(tmp);
	tail->next=head;
	}
}

void deleteend()
{
	if(head==tail && head->next==head)
	{
		printf("Deletion done of %d",head->data);
		free(head);
		head=NULL;
		tail=NULL;
	}
	else
	{
		node *tmp;
		tmp=head;
		while(tmp->next!=tail)
		{
			tmp=tmp->next;
		}
			printf("Deletion done of %d",tail->data);
			free(tail);
			tail=tmp;
			tail->next=head;
	}
}

void deletemiddle()
{
	int pos,a;
	printf("enter position for deletion\n");
	scanf("%d",&pos);
	if(pos==1)
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
			if(tmp1==tail)
			{
				deleteend();
			}
			else
			{
			tmp->next=tmp1->next;
			printf("Deletion done of %d",tmp1->data);
			free(tmp1);	
			}
		}
		else
		{
			printf("wrong input\n");
		}
	}
}

void display()
{
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		node *tmp;
		tmp=head;
		while(tmp->next!=head)
		{
			printf("%d\t",tmp->data);
			tmp=tmp->next;
		}
	printf("%d\t",tmp->data);
	printf("%d",tail->next->data);			
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


