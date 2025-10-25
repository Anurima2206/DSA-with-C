#include<stdio.h>
int partition(int a[],int s,int e)
{
	int pivot=a[e];
	int pindex=s;
	for(int i=s;i<=e-1;i++)
	{
		if(a[i]<=pivot)
		{
			int temp=a[i];
			a[i]=a[pindex];
			a[pindex]=temp;
			pindex++;
		}
	}
	int temp1=a[e];
	a[e]=a[pindex];
	a[pindex]=temp1;
	return pindex;
}
void quicksort(int a[],int s,int e)
{
	if(s<e)
	{
		int p=partition(a,s,e);
		quicksort(a,s,(p-1));
		quicksort(a,(p+1),e);
	}
}
int main()
{
	int a[100],n,i;
	printf("Enter array length: ");
	scanf("%d",&n);
	printf("enter array elements:\n");
	for(i=0;i<n;i++)
	{	
	scanf("%d",&a[i]);
	}
	printf("The array elements before sorting:\n");
	for(i=0;i<n;i++)
	{
	printf("%d\n",a[i]);
	}
	quicksort(a,0,n-1);
	printf("The array element after sorting:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}

