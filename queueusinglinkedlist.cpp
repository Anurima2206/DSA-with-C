#include<stdio.h>
#include<stdlib.h>
typedef struct linkedlist
{
	int data;
	struct linkedlist *next;
}node;
node *front,*rear;

void create()
{
	front=rear=NULL;
}
void enqueue(int no)
{
	node *nw;
	nw=(node*)malloc(sizeof(node));
	nw->data=no;
	nw->next=NULL;
	if(front==NULL && rear==NULL)
	{
	front=rear=nw;
	rear->next=front->next=NULL;
	}
	else
	{
	rear->next=nw;
	rear=nw;
	rear->next=NULL;
	}
printf("insertion done of %d",nw->data);
}

void dequeue()
{
	node *ptr;
	if(front==NULL)
	{
		printf("queue underflow");
	}
	else
	{
		if(front==rear)
		{
		ptr=front;
		front=ptr->next;
		printf("deletion done of %d",ptr->data);	
		free(ptr);
		front=NULL;
		rear=NULL;	
		}
		else
		{
		ptr=front;
		front=ptr->next;
		printf("deletion done of %d",ptr->data);	
		free(ptr);
		}
	}
}

void display()
{
	node *ptr;
	if(front==NULL && rear==NULL)
	{
		printf("queue underflow");
	}
	else
	{
		ptr=front;
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
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("enter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				int n1;
				printf("enter any no.");
				scanf("%d",&n1);
				enqueue(n1);
			break;
			case 2:
				dequeue();
			break;
			case 3:
				display();
			break;
			case 4:
				exit(0);
			default:
				printf("wrong input");
			
		}
	}
}

