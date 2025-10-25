#include<stdio.h>
int main()
{
	int a[20],i,n,tmp,j;
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
for(i=0;i<n;i++)
{
	for(j=0;j<n-1;j++)
	{
		if(a[j]>a[j+1])
		{
			tmp=a[j];
			a[j]=a[j+1];
			a[j+1]=tmp;
		}
	}
}
printf("the array after sorting:\n");
for(i=0;i<n;i++)
{
printf("%d\n",a[i]);
}
}
