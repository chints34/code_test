#include <stdio.h>

int main()
{
int a  = 1;
//printf("%d\n",a);
//a=a>>1;
int i;
for(i=32;i>0;i--)
a&(1<<i)?puts("1"):puts("0");
//printf("%d\n",a);
return 0;
}
