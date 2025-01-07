#include <stdio.h>
#include <stdlib.h>
int main()
{
int i, n, temp, j, arr[10];
printf("Enter the maximum elements you want to store : ");
scanf("%d", &n);
printf("Enter the elements \n");
for(i=0;i<n;i++)
{
scanf("%d", & arr[i]);
}
for(i=0;i<n;i++)
{
for(j=0;j<n-1;j++)
{
if(arr[j]>arr[j+1])
{
temp = arr[j];
arr[j] = arr[j+1];
arr[j+1] = temp;
}
}
}
printf("The array sorted in ascending order is :\n");
for(i=0;i<n;i++)
printf("%d\t", arr[i]);
return 0;
}