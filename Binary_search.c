#include<stdio.h>
void main()
{
int first, last, middle, size, i, key, list[100];
printf("Enter the size of the list: ");
scanf("%d",& size);
printf("Enter %d integer values in Ascending order\n", size);
for (i = 0; i < size; i++)
{
scanf("%d",&list[i]);
}
printf("Enter value to be search: ");
scanf("%d", &key);
first = 0;
last = size - 1;
middle = (first+last)/2;
while (first <= last)
{
if (list[middle] <key)
{
first = middle + 1;
}
else if (list[middle] == key)
{
printf("Element found at index %d.\n",middle);
break;
}
else
{
last = middle - 1;}
middle = (first + last)/2;
}
if (first > last)
{
printf("Element Not found in the list.");
}
}