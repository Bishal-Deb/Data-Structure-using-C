#include<stdio.h>

struct node{
	int data; 
	struct node *left, *right;
};

struct node *Create(){   //return pointer to node
	int x;
	struct node *newnode;
	newnode= (struct node*)malloc(sizeof(struct node));
	printf("Enter data(-1 for no node): ");
	scanf("%d", &x);

	if(x==-1)
	{ return 0; }

	newnode -> data=x;

	printf("Enter the left child of %d ",x);
	newnode->left= Create();
	printf("Enter right child of %d ",x );
	newnode->right= Create();
	return newnode;	
}

int main(){
	struct node *root;
	root=0;
	root=Create();
}

