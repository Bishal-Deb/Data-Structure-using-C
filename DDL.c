#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define x 50
struct node{
    struct node *prev;
    struct node *next;
    int pid;
    char status[x];
    int priority;
};
struct node *head;

void add_process(int p, int n, char s[x]){
 struct node *ptr, *temp;
 ptr=(struct node*)malloc(sizeof(struct node));
 ptr->pid=p;
 ptr->priority=n;
 strcpy(ptr->status,s);
 
 if(head==NULL){
     head=ptr;
     head->prev=NULL;
     ptr->next=NULL;
 }
 else{
     temp=head;
     while(temp->next != NULL)
       temp=temp->next;
    temp->next=ptr;
    ptr->prev=temp;
    ptr->next=NULL;
 }
printf("\nProcess added sucessfully");
}

void remove_process(){
    struct node *ptr, *temp,*temp1, *temp2;
    int p;
    int flag=0;
    printf("\nEnter the Process Id to remove:");
    scanf("%d",&p);
    if(head==NULL){
        printf("\n process list is empty ");
    }
    else if(head->pid==p)
    {
        printf("\n Process has been deleted");
        head=head->next;
    }
    else
    {
         temp = head;
         while(temp!=NULL){
             if(temp->pid==p){
                flag=1;
                break;
            }
              temp=temp->next;
        }
        if(flag==1){
        temp1=temp->next;
        temp2=temp1->next;
        temp->next=temp2;
        temp2->prev=temp;
        free(temp1);
         printf("\n process deleted!!!");
        }
    else
    {
          printf("\n process not found.");
    }
      
    }
}
void display(){
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("\t Pid %d \t Status %s \t Priority %d \n",temp->pid,temp->status,temp->priority);
        temp=temp->next;
    }
}
void display_ready()
{
    struct node *tmp;
    tmp=head;
    if(tmp==NULL)
    {
        printf("\n there are no ready process");
    }
    else
    {
    while(tmp != NULL)
    {
       if (strcmp(tmp->status,"ready")==0)
         printf("\n \t Pid: %d \t Status: %s",tmp->pid,tmp->status);
      tmp=tmp->next;
    }
    }

}
void display_max()
{
    int max=head->priority;
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->priority>max)
            max=temp->priority;
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL)
    {
        if(temp->priority==max)
        {
            printf("\n The highest priority process is:");
            printf("Pid:%d \tStatus:%s \t Priority:%d\n",temp->pid,temp->status,temp->priority);
            
        }
        temp=temp->next;
    }
}
int main()
{
    int ch;
    int p,n;
    char s[x];
    while(1)
    {
        printf("\n\n 1. ADD a process \n 2.DELETE a process \n 3.DISPLAY all process \n 4.Display ready process\n 5.display highest priority process \n 6.EXIT");
        printf("\n Enter your Choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("\n Enter Process Id:");
            scanf("%d",&p);
            printf("\n Enter process status(ready,runnnig,wait):");
            scanf("%s",s);
            printf("\nEnter the priority of the process:");
            scanf("%d",&n);
            if (strcmp(s,"ready")!=0 || strcmp(s,"running")!=0 || strcmp(s,"wait")!=0)
            {
                printf("\n WRONG process status!!! \n Enter Correct Process Status");
                break;
            }
            else
            {
               add_process(p,n,s);
               break;
            }
        case 2:
             remove_process();
             break;
        case 3:
             display();
             break;
        case 4:
             display_ready();
             break;
        case 5:
             display_max();
             break;
        case 6:
            exit(0);
        }

    }
    return 0;
}