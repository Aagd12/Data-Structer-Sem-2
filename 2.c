#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int coficent;
    int power;
    struct node *next;
};
struct node *crateanodeandinsertlast(int coficent,int power,struct node* Hade)
{
    if(Hade==NULL)
    {
        struct node *new_node;
        new_node=(struct node *)malloc(sizeof(struct node));
        new_node->coficent=coficent;
        new_node->power=power;
        new_node->next=NULL;
        Hade=new_node;

        return Hade;
    }
    else
    {

        struct node *new_node;
        new_node=( struct node *)calloc(1,sizeof(struct node));
        new_node->coficent=coficent;
        new_node->power=power;
        new_node->next=NULL;
        Hade->next=new_node;
        Hade=new_node;
        return Hade;
    }
}
void print(struct node*hade)
{
    printf("polynomial\n");
    while(hade!=NULL)
    {
        printf("%d*x^%d  ",hade->coficent,hade->power);

        hade=hade->next;
        if(hade==NULL )break;
        if(hade->coficent<0)
        {
            printf("");
        }
        else printf("+");
    }
}
void finding(struct node*hade1)
{
    int count=1,flag=1;
    struct node* p1=hade1;
    int max_coficent=p1->coficent;
    int max_power=p1->power;
    while(p1->next!=NULL)
    {
        if(p1->next->coficent>max_coficent)
        {
            max_coficent=p1->next->coficent;
            count++;
        }
        if(p1->next->power>max_power)
        {
            max_power=p1->next->power;
            flag++;
        }

        p1=p1->next;
    }
    printf("max coficent is %d is in %d term and max power is %d is in %d term \n",  max_coficent,count, max_power,flag);
}
void add(struct node*hade1,struct node*hade2)
{
    int count=0;
    for( struct node* p1=hade1; p1!=NULL; p1=p1->next)
    {
        for( struct node* p2=hade2; p2!=NULL; p2=p2->next)
        {
            if(p1->power==p2->power)
            {
                if(p1->next==NULL)
                {
                    printf(" %d*x^%d ",(p1->coficent+p2->coficent),p1->power);
                    count++;
                }
                else
                {
                    printf(" %d*x^%d +",(p1->coficent+p2->coficent),p1->power);
                    count++;

                }

            }

        }
        if(count==0)
        {

            printf(" %d*x^%d +",p1->coficent,p1->power);

        }
        count=0;
    }

    for( struct node* p2=hade2; p2!=NULL; p2=p2->next)
    {
        for( struct node* p1=hade1; p1!=NULL; p1=p1->next)
        {
            if(p2->power!=p1->power)
            {

            }
            else break;
            if(p1->next==NULL)
            {
                if(p2->next==NULL)
                {
                    printf(" %d*x^%d  ",p2->coficent,p2->power);
                }
                else
                    printf(" %d*x^%d + ",p2->coficent,p2->power);
            }
        }
    }
}
void sub(struct node*hade1,struct node*hade2)
{
    int count=0;
    for( struct node* p1=hade1; p1!=NULL; p1=p1->next)
    {

        for( struct node* p2=hade2; p2!=NULL; p2=p2->next)
        {
            if(p1->power==p2->power)
            {
                if(p1->next==NULL)
                {
                    printf(" %d*x^%d ",(p1->coficent-p2->coficent),p1->power);
                    count++;
                }
                else
                {
                    printf(" %d*x^%d +",(p1->coficent-p2->coficent),p1->power);
                    count++;

                }

            }

        }
        if(count==0)
        {

            printf(" %d*x^%d +",p1->coficent,p1->power);
            count=0;

        }
        count=0;
    }

    for( struct node* p2=hade2; p2!=NULL; p2=p2->next)
    {
        for( struct node* p1=hade1; p1!=NULL; p1=p1->next)
        {
            if(p2->power!=p1->power)
            {

            }
            else break;
            if(p1->next==NULL)
            {
                if(p2->next==NULL)
                {
                    printf(" %d*x^%d  ",(-1*p2->coficent),p2->power);
                }
                else
                    printf(" %d*x^%d + ",(-1*p2->coficent),p2->power);
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    int terms1,power,coficent,terms2;
    struct node* Hade=NULL;
    struct node*first;
    struct node *hade=NULL;
    printf(" enter number of terms in list 1 ");
    scanf("%d", &terms1);
    printf(" enter the cofficent with sign and power ");
    for(int i=0; i<terms1; i++)
    {
        scanf("%d %d",&coficent,&power);
        if(i==0)
        {
            Hade= crateanodeandinsertlast(coficent,power,Hade);
            first=Hade;
        }
        else
            first= crateanodeandinsertlast(coficent,power,first);
    }
    print(Hade);
    printf(" enter number of terms in list 2 ");
    scanf("%d", &terms2);
    printf(" enter the cofficent with sign and power ");
    for(int i=0; i<terms2; i++)
    {
        scanf("%d %d",&coficent,&power);
        if(i==0)
        {
            hade= crateanodeandinsertlast(coficent,power,hade);
            first=hade;
        }
        else
            first= crateanodeandinsertlast(coficent,power,first);
    }

    print(hade);
    printf("about to first polynomial\n");
    finding(Hade);
    printf("about to second polynomial\n");
    finding(hade);
    /* printf("\nsum of two polynomial\n");
     add(Hade,hade);
     printf("\n substraction of two polynomial\n");
     sub(Hade,hade);
     printf("\n substraction of two polynomial\n");
     sub(hade,Hade);*/
    return 0;
}

