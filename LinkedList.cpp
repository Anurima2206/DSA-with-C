#include<stdio.h>
#include<stdlib.h>
typedef struct linkedlist node;
 struct linkedlist
{
	int data;
	struct linkedlist *next;	
};
int main()
{
	node *ptr,*ptr1,*ptr2;
	//1st node
	ptr=(node*)malloc(sizeof(node));
	printf("Enter any number");
	scanf("%d",&ptr->data);
	ptr->next=NULL;
	//2nd node
	ptr1=(node*)malloc(sizeof(node));
	printf("Enter any number");
	scanf("%d",&ptr1->data);
	ptr1->next=NULL;
	//3rd node
	ptr2=(node*)malloc(sizeof(node));
	printf("Enter any number");
	scanf("%d",&ptr2->data);
	ptr2->next=NULL;
	//link to linklist
	ptr->next=ptr1;
	ptr1->next=ptr2;
	printf("%d %d %d",ptr->data,ptr->next->data,ptr->next->next->data);
}
