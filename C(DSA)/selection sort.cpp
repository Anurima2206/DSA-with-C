#include<stdio.h>
int main()
{
	int a[20],n,i,j,min,tmp;
	printf("Enter array length");
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
for(i=0;i<n;i++)
{
	min=i;
	for(j=i+1;j<n;j++)
	{
		if(a[min]>a[j])
		{
			min=j;
		}
	}
	tmp=a[min];
	a[min]=a[i];
	a[i]=tmp;
}
printf("the array after sorting");
for(i=0;i<n;i++)
{
	printf("%d\n",a[i]);
}
}
