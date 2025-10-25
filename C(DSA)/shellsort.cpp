#include<stdio.h>
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
for(int gap=n/2;gap>0;gap/=2)
{
	for(int j=gap;j<n;j++)
	{
		int temp=a[j];
		int i=0;
		for(i=j;(i>=gap)&&(a[i-gap]>temp);i-=gap)
		{
			a[i]=a[i-gap];
		}
		a[i]=temp;
	}
}
printf("the array after sorting:\n");
for(i=0;i<n;i++)
{
printf("%d\n",a[i]);
}
}
