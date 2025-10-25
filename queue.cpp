#include<stdio.h>
#include<stdlib.h>
#define max 5
int front,rear,n[max],num,ch;
void create()
{
	front=-1;
	rear=-1;
}
void enqueue(int num)
{
	if(rear+1==max)
	{
		printf("queue overflow\n");
	}
	else
	{
		rear++;
		n[rear]=num;
		if(front==-1)
		{
			front=0;
		}
		printf("Insertion of element %d done\n",n[rear]);
	}
}
void dequeue()
{
	if(front==-1 || front>rear)
	{
		printf("queue underflow\n");
	}
	else
	{
		printf("the deleted element is %d\n",n[front]);
		front++;
	}
}
void display()
{
	int i;
	if(rear==-1 && front==-1)
	{
		printf("queue underflow\n");
	}
	else if(rear==-1 || front>rear)
	{
		printf("nothing\n");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d\t",n[i]);
		}
	}
}
int main()
{
	create();
	while(1)
	{
		int ch;
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
		printf("\nEnter choice");
		scanf("%d",& ch);
		switch(ch)
		{
			case 1:
				printf("enter element to be inserted");
				scanf("%d",&num);
				enqueue(num);
			break;
			case 2:
				dequeue();	
			break;
			case 3:
				display();
			break;
			case 4:
				exit(0);
			break;
			default:
				printf("wrong choice\n");
		}				
	}
}
