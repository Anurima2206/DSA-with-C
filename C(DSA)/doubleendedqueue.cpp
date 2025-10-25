#include<stdio.h>
#include<stdlib.h>
#define max 5
int front,rear,n[max],num,ch,ins,del;
void create()
{
	front=-1;
	rear=-1;
}
void enqueuerear(int num)
{
	if((rear+1==max && front==0)||(front==rear+1))
	{
		printf("queue overflow\n");
	}
	else if(front==-1 && rear==-1)
	{
		front++;
		rear++;
		n[rear]=num;
		printf("insertion done of element %d\n",n[rear]);
	}
	else if(rear+1==max)
	{
		rear=0;
		n[rear]=num;
		printf("insertion done of element %d\n",n[rear]);
	}
	else
	{
		rear++;
		n[rear]=num;
		if(front==-1)
		{
			front++;
		}
		printf("insertion done of element %d\n",n[rear]);
	}
}
void enqueuefront(int num)
{
	if((rear+1==max && front==0)||(front==rear+1))
	{
		printf("queue overflow\n");
	}
	else if(front==-1 && rear==-1)
	{
		front++;
		rear++;
		n[front]=num;
		printf("insertion done of element %d\n",n[front]);
	}
	else
	{
		if(front==0)
		{
			rear++;
			for(int i=rear;i>front;i--)
			{
				n[i]=n[i-1];
			}
		}
		else
		{
			front--;
		}
		n[front]=num;
		printf("insertion done of element %d\n",n[front]);
	}
}
void dequeuefront()
{
 	if(front==-1 && rear==-1)
	{
		printf("queue underflow\n");
	}
	else if(front==rear)
	{
		printf("the deleted element is %d\n",n[front]);
		front=-1;
		rear=-1;
	}
	else if(front+1==max)
	{
		printf("the deleted element is %d\n",n[front]);
		front=0;
	}
	else
	{
		printf("the deleted element is %d\n",n[front]);
		front++;
	}
}
void dequeuerear()
{
	if(front==-1 && rear==-1)
	{
		printf("queue underflow\n");
	}
	else if(front==rear)
	{
		printf("the deleted element is %d\n",n[rear]);
		front=-1;
		rear=-1;
	}
	else if(rear==0)
	{
		printf("the deleted element is %d\n",n[rear]);
		rear=max-1;
	}
	else
	{
		printf("the deleted element is %d\n",n[rear]);
		rear--;
	}
}
void display()
{
	int i;
	if(front==-1 && rear==-1)
	{
		printf("queue underflow\n");
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
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n1.Enqueue rear\n2.Enqueue front");
				printf("\nenter choice for insertion");
				scanf("%d",&ins);
				switch(ins)
				{
				case 1:
					printf("\nenter element to be inserted");
					scanf("%d",&num);
					enqueuerear(num);
					break;
				case 2:
					printf("\nenter element to be inserted");
					scanf("%d",&num);
					enqueuefront(num);
					break; 	 	
				default:
					printf("\nwrong choice");
				}
				break;
			case 2:
				printf("\n1.Dequeue front\n2.Dequeue rear");
				printf("\nenter choice for deletion");
				scanf("%d",&del);
				switch(del)
				{
				case 1:
					dequeuefront();
					break;
				case 2:
					dequeuerear();
					break;
				default:
					printf("\nwrong choice");
						
						
				}
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
