#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;

};
void insertinglistat_end(struct node **head,int data)
{
    if(*head==NULL)
    {
        struct node *newnode= (struct node *)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->next=NULL;
        *head=newnode;

    }
    else
    {
        struct node *newnode= (struct node *)malloc(sizeof(struct node));
        struct node*temp=*head;
        newnode->data=data;
        newnode->next=NULL;
        while(temp->next)
            temp=temp->next;
        temp->next=newnode;
    }


}
void insertinglistat_begin(struct node **head,int data)
{

        struct node *newnode= (struct node *)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->next=*head;
        *head=newnode;

}

struct node* Reverse(struct node* p)
{
    struct node* front = p;
    struct node* temp = NULL;
    struct node* tail = NULL;


    while(p)
    {
        temp = tail;
       tail=p;
        p=p->next;
        tail->next=temp;
    }
    printf("\n\nReverse S_LL is: ");
    return tail;
}
void print(struct node *head)
{
    while(head)
    {
        printf("%d->",head->data);
        head=head->next;
    }
   printf("NULL");
}


int main()
{
    int data;
    struct node *head=NULL;
    printf("enter data");
    scanf("%d",&data);
    insertinglistat_end(&head,data);
    printf("enter data");
    scanf("%d",&data);
    insertinglistat_end(&head,data);
    printf("enter data");
    scanf("%d",&data);
    insertinglistat_end(&head,data);
    print(head);
     printf("enter data");
    scanf("%d",&data);
     insertinglistat_begin(&head,data);
      printf("enter data");
    scanf("%d",&data);
      insertinglistat_begin(&head,data);
       printf("enter data");
    scanf("%d",&data);
       insertinglistat_begin(&head,data);
      print(head);
      print(Reverse(head));
    return 0;
}
