#include<stdio.h>
#include<stdlib.h>
typedef struct polynomial
{
	int co,exp;
	struct polynomial *next;
}node;
node* create(node *head,int coeff,int expo)
{
	node *temp,*flag;
	if(head==NULL)
	{
		temp=(node *)malloc(sizeof(node ));
		temp->co=coeff;
		temp->exp=expo;
		temp->next=NULL;
		head=temp;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		flag=(node *)malloc(sizeof(node ));
		flag->co=coeff;
		flag->exp=expo;
		flag->next=NULL;
		temp->next=flag;
	}
	return head;
}
node* PolyAdd(node *p1,node *p2,node *sum)
{
	node *poly1=p1,*poly2=p2,*res;
	if(poly1!=NULL && poly2==NULL)
	{
		sum=poly1;
		return sum;
	}
	else if(poly1==NULL && poly2!=NULL)
	{
		sum=poly2;
		return sum;
	}
	while(poly1!=NULL && poly2!=NULL)
	{
		if(sum==NULL)
		{
			sum=(node *)malloc(sizeof(node ));
			res=sum;
		}
		else
		{
			res->next=(node *)malloc(sizeof(node ));
			res=res->next;
		}
		if(poly1->exp > poly2->exp)
		{
			res->co=poly1->co;
			res->exp=poly1->exp;
			poly1=poly1->next;
		}
		else if(poly1->exp < poly2->exp)
		{
			res->co=poly2->co;
			res->exp=poly2->exp;
			poly2=poly2->next;
		}
		else if(poly1->exp == poly2->exp)
		{
			res->co=poly1->co+poly2->co;
			res->exp=poly1->exp;
			poly1=poly1->next;
			poly2=poly2->next;
		}
	}
	while(poly1!=NULL)
	{
		res->next=(node *)malloc(sizeof(node));
		res=res->next;
		res->co=poly1->co;
		res->exp=poly1->exp;
		poly1=poly1->next;
	}
	while(poly2!=NULL)
	{
		res->next=(node *)malloc(sizeof(node));
		res=res->next;
		res->co=poly2->co;
		res->exp=poly2->exp;
		poly2=poly2->next;
	}
	res->next=NULL;
	return sum;
}
void display(node *head)
{
	node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d^%d+",temp->co,temp->exp);
		temp=temp->next;
	}
	printf("\n");
}
int main()
{
	node *p1=NULL,*p2=NULL,*sum=NULL;
	int ch,coeff,expo;
	while(1)
	{
		printf("\n1.insert 1st polynomial\n");
		printf("\n2.insert 2nd polynomial\n");
		printf("\n3.addition of two polynomial\n");
		printf("\n4.exit\n");
		printf("\nenter any option:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter coefficient:");
				scanf("%d",&coeff);
				printf("enter exponent:");
				scanf("%d",&expo);
				p1=create(p1,coeff,expo);
			break;
			case 2:
				printf("enter coefficient:");
				scanf("%d",&coeff);
				printf("enter exponent:");
				scanf("%d",&expo);
				p2=create(p2,coeff,expo);
			break;
			case 3:
				printf("\n1st polynomial\n");
				display(p1);
				printf("\n2nd polynomial\n");
				display(p2);
				sum=PolyAdd(p1,p2,sum);
				printf("\nsum is\n");
				display(sum);
			break;
			case 4:
				exit(0);
			break;
			default:
				printf("wrong choice");					
		}
	}
}
