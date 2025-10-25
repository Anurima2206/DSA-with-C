#include<stdio.h>
#include<stdlib.h>
#define max 5
int top,n[max],num,ch;
void create()
{
	top=-1;
}
void push(int num)
{
	if(top+1==max)
	{
		printf("stack overflow\n");
	}
	else
	{
		top++;
		n[top]=num;
	printf("insertion done of element %d\n",n[top]);
	}
}
void pop()
{
	if(top==-1)
	{
		printf("stack underflow\n");
	}
	else
	{
		printf("the deleted element is %d\n",n[top]);
		top--;
	}
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("stack underflow\n");
	}
	else
	{
		for(i=top;i>=0;i--)
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
		printf("\n1.Push\n");
		printf("2.Pop\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		printf("enter choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter number to be added");
				scanf("%d",&num);
				push(num);
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
				printf("wrong choice\n");	
		}
	}
}
