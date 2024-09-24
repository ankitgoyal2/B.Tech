#include<stdio.h>
void main()
{
int arr[10],i,s;
printf("enter the elements of the array \n");
for(i=0;i<10;i++)
{
scanf("%d",&arr[i]);
}
s=arr[0];
for(i=1;i<10;i++)
{
if(arr[i]<s)
s=arr[i];
}
printf(" smallest element in the array is %d \n",s);
printf("odd elements are ");
for(i=0;i<10;i++)
  {
if(arr[i]%2==1)
printf(" %d",arr[i]);
}
printf("\neven elements are");
for(i=0;i<10;i++)
{
 if(arr[i]%2==0)
 printf(" %d",arr[i]);
}
}
