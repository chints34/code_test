#include <stdio.h>
int main()
{
int num,i,j;
printf("enter a integer value:");
scanf("%d",&num);
	for(i=31;i>=0;i--)
		num & (1<<i) ? printf("1"):printf("0");
for(i=0,j=31;i<j;i++,j--)
{
if( ((num>>i)&1)^((num>>j)&1) ) 
	{
		num=num^(1<<i);
		num=num^(1<<j);
	}
}


printf("\nrevrse bit integer: %d\n",num);
	for(i=31;i>=0;i--)
		num & (1<<i) ? printf("1"):printf("0");
return 0;
}
