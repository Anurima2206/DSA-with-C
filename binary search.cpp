#include<stdio.h>
int main()
{
	int a[20],f,i,n,ele,mid,beg,end;
printf("Enter n");
scanf("%d",&n);
printf("enter array elements:\n");
for(i=0;i<n;i++)
{
	scanf("%d",&a[i]);
}
printf("The array elements:\n");
for(i=0;i<n;i++)
{
	printf("%d\n",a[i]);
}
printf("Enter element to be found\n");
scanf("%d",& ele);
beg=0,end=n-1;
while(beg<=end)
{
	mid=(beg+end)/2;
	if(a[mid]==ele)
	{
		printf(" The element %d Found at position %d",ele,mid+1);
		f=1;
		break;
	}
	else if(a[mid]<ele)
	{
		beg=mid+1;
	}
	else
	{
		end=mid-1;
	}
}
if(f==0)
{
	printf("element not found");
}
}
