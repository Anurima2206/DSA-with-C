#include<stdio.h>
#include<stdlib.h>
typedef struct BST_node
{
	int item;
	struct BST_node *left;
	struct BST_node *right;
}BST;
void CreateTree(BST **tree)
{
	*tree=NULL;
}
void InsertElement(BST **tree,int ele)
{
	if(*tree==NULL) 
	{
		*tree=(BST *)malloc(sizeof(BST));
		(*tree)->item=ele;
		(*tree)->left=(*tree)->right=NULL;
	}
	else
	{
		if(ele<(*tree)->item)
		{
			InsertElement(&(*tree)->left,ele);
		}
		else 
		{
			InsertElement(&(*tree)->right,ele);
		}
	}
}
void PreOrder(BST *p)
{
	if(p!=NULL)
	{
		printf(" %d ",p->item);
		PreOrder(p->left);
		PreOrder(p->right);
	}
}
void InOrder(BST *p)
{
	if(p!=NULL)
	{
		InOrder(p->left);
		printf(" %d ",p->item);
		InOrder(p->right);
	}
}
void PostOrder(BST *p)
{
	if(p!=NULL)
	{
		PostOrder(p->left);
		PostOrder(p->right);
		printf(" %d ",p->item);
	}
}
BST *FindLargest(BST *p)
{
	while(p->right!=NULL)
	{
		p=p->right;
	}
	return p;
}
BST *FindSmallest(BST *p)
{  
    while(p->left != NULL)
	{  
        p = p->left;  
    }  
    return p;  
}  
void DeleteElement(BST **tree,int ele)
{
	BST *temp;
	if(*tree==NULL)
	{
		printf("element is not found");
	}
	else if(ele<(*tree)->item)
	{
		DeleteElement(&(*tree)->left,ele);
	}
	else if(ele>(*tree)->item)
	{
		DeleteElement(&(*tree)->right,ele);
	}
	else if((*tree)->left && (*tree)->right)
	{
		temp=FindLargest((*tree)->left);
		(*tree)->item=temp->item;
		DeleteElement(&(*tree)->left,temp->item);
	}
	else
	{
		temp=*tree;
		if((*tree)->left==NULL && (*tree)->right==NULL)
		{
			*tree=NULL;
		}
		else if((*tree)->left!=NULL)
		{
			(*tree)=(*tree)->left;
		}
		else
		{
			(*tree)=(*tree)->right;
		}
		free(temp);
	}
}
int TotalNodes(BST *p)
{
	//int count=1;
	if(p==NULL)
	{
		return 0;
	}
	else
	{
		/*count=count+TotalNodes(p->left);
		count=count+TotalNodes(p->right);
		return count;*/	
		return (1+TotalNodes(p->left)+TotalNodes(p->right));
	}
}
int main()
{
	int choice,ele;
	BST *root,*loc;
	//root=NULL;
	CreateTree(&root);
	while(1)
	{
		printf("\n1.insert node in tree\n");
		printf("2.pre-order traversal\n");
		printf("3.in-order traversal\n");
		printf("4.post-order traversal\n");
		printf("5.delete node\n");
		printf("6.total node\n");
		printf("7.found largest element\n");
		printf("8.found smallest element\n");
		printf("9.exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("enter element which you want to insert:");
				scanf("%d",&ele);
				InsertElement(&root,ele);
			break;
			case 2:
				PreOrder(root);
			break;
			case 3:
				InOrder(root);
			break;
			case 4:
				PostOrder(root);
			break;
			case 5:
				printf("enter element which you want to delete:");
				scanf("%d",&ele);
				DeleteElement(&root,ele);
			break;
			case 6:
				printf("total number of nodes %d",TotalNodes(root));
			break;
			case 7:
				loc=FindLargest(root);
				printf("the largest element is %d",loc->item);
			break;
			case 8:
				loc=FindSmallest(root);
				printf("the smallest element is %d",loc->item);
			break;
			case 9:
				exit(0);
			break;
			default:
				printf("wrong choice");
		}
	}
}
