#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
void insert(int);
struct node
{
int data;
struct node *left;
struct node *right;
};
struct node *root;
int main ()
{
int choice,item;
do
{
cout<<"\nEnter the item which you want to insert?\n";
cin>>item;
insert(item);
cout<<"\n Press 0 to insert more? \n";
cin>>choice;
}while(choice == 0);
return 0;
}
void insert(int item)
{
struct node *ptr, *parentptr , *nodeptr;
ptr = (struct node *) malloc(sizeof (struct node));
if(ptr == NULL)
{
cout<<"cannot insert";
}
else
{
ptr -> data = item;
ptr -> left = NULL;
ptr -> right = NULL;
if(root == NULL)
{
root = ptr;
root -> left = NULL;
root -> right = NULL;
}
else
{
parentptr = NULL;
nodeptr = root;
while(nodeptr != NULL)
{
parentptr = nodeptr;
if(item < nodeptr->data)
{
nodeptr = nodeptr -> left;
}
else
{
nodeptr = nodeptr -> right;
}
}
if(item < parentptr -> data)
{
parentptr -> left = ptr;
}
else
{
parentptr -> right = ptr;
}
}
cout<<"Node Inserted";
}}