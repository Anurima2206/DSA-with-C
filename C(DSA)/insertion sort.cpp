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
for(i=1;i<n;i++)
{
	tmp=a[i];
	j=i-1;
	while(tmp<a[j]&&j>=0)
	{
		a[j+1]=a[j];
		j=j-1;
}
a[j+1]=tmp;
}
printf("The array after sorting");
for(i=0;i<n;i++)
{
	printf("%d\n",a[i]);
}
}
