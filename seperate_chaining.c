#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
struct node
{
	int data;
	struct node *next;
};
struct node *chain[SIZE];
void init()
{
    int i;
    for(i = 0; i <SIZE; i++)
        chain[i] = NULL;
}
void insert(int v)
{
	int key;
	struct node *e=(struct node*)malloc(sizeof(struct node));
	e->data=v;
	e->next=NULL;
	key=v%SIZE;
	printf("Key=%d\n",key);
	if(chain[key]==NULL)
		chain[key]=e;
	else
	{
		struct node *p,*q;
		p=chain[key];
		q=p->next;
		while(q!=NULL)
		{
			p=p->next;
			q=q->next;
		}
		p->next=e;
	}
}
void print()
{
    int i;
    printf("The hash table looks as follows:\n");

    for(i = 0; i <SIZE; i++)
    {
        struct node *temp = chain[i];
        printf("chain[%d]-->",i);
        while(temp)
        {
            printf("%d -->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int c=1,item;
    init();
	while(c!=0)
	{
		printf("\nEnter the value of the item you want to insert in the table:");
		scanf("%d",&item);
		insert(item);
		printf("Keep inserting? Press 1-Yes and 0-No:");
		scanf("%d",&c);
	}
    

    print();

    return 0;
}
