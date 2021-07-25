#include <stdio.h>
#include <stdlib.h>
  struct stack
{
    int top1;
    int *a1;

}*st1;
 struct stack2
{
    int top2;
    int *a2;

}*st2;
void creatstack(int size)
{
    st1->top1=-1;
    st1->a1=(int*)calloc(size,sizeof(int));
    st2->top2=-1;
    st2->a2=(int*)calloc(size,sizeof(int));
}
void print()
{
    int i=0;
    printf("elment of queee:");
    while(i<=st1->top1)
    {
        printf("%d",st1->a1[i]);
        i++;
    }
}
void pushs1(int elment)
{
    st1->a1[++st1->top1]=elment;
}
void pushs2(int elment)
{
    st2->a2[++st2->top2]=elment;
}
int  pops1()
{
    return st1->a1[st1->top1--];
}
int  pops2()
{
    return st2->a2[st2->top2--];
}
void Enquee()
{
    int elment;
    printf("enter  elment  which is inserted in quee:");
    scanf("%d",&elment);
    pushs1(elment);
}
void dequee()
{
    while(st1->top1!=-1)
    {
        int temp=pops1();
        pushs2(temp);
    }
    printf("%d is delated elment from quee:\n", pops2()) ;
    while(st2->top2!=-1)
    {
        int temp=pops2();
        pushs1(temp);
    }
}
int main()
{
    int size;
    printf("enter size of quee:");
    scanf("%d",&size);
    creatstack(size);
    int ch;
    printf("\n1 - Enqueue element into queue");
    printf("\n2 - Dequeue element from queue");
    printf("\n3 - Display from queue");
    printf("\n4 - Exit");
    while (1)
    {
        printf("\nEnter choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            Enquee();
            break;
        case 2:
            dequee();
            break;
        case 3:
          print();
            break;
        case 4:
            exit(0);
        default:
            printf("Please choose correct choice! ");
        }
    }
    return 0;
}
