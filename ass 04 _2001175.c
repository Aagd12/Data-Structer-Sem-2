#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int  data;
    int top;
    int size;
    int *array;

} stack;

void creatingstack(struct stack *st)
{
    st->top=-1;
    st->array=(int *)calloc(st->size,sizeof(int ));
};
int stackisempty(struct stack *st)
{
    if(st->top==-1)return 1;
    else return 0;
};
int stackisfull(struct stack *st)
{
    if(st->top==st->size-1)return 0;
    else return 1;
};
void push(struct stack *st,int data)
{

    if(stackisfull(st))
    {
        st->array[++st->top]=data;
    }
    else printf("stack is full\n");
}

void pop(struct stack *st)
{
    int  data;
    if(stackisempty(st))
        printf("stack is empty\n");
    else
    {
        data=st->array[st->top--];
    }
}
void print(struct stack st)
{
    int i=0;
    if(st.top==-1)
    {
        printf("empty\n");
    }
    while(i<=st.top)
    {
        printf("%d",st.array[i++]);
    }
    printf("\n");
}
int isopratend(char in)
{
    if(in=='+'||in=='-'||in=='*'||in=='/')
    {
        return 0;
    }
    else return 1;
}
int isprecedence(char in)
{
    if(in=='+'||in=='-')
    {
        return 1;
    }
    else return 2;
}
void  evaluation_postfix_expression( char* postfix,struct stack *st1)
{

    int i=0,result;
    int  oprend1,oprend2;
    int size= strlen(postfix);
    while(i<size)
    {

        if(isopratend(postfix[i]))
        {
            push(st1,postfix[i++]-'0');

        }
        else
        {
            oprend2=st1->array[st1->top];
            pop(st1);
            oprend1=st1->array[st1->top];

            pop(st1);
            if(postfix[i]=='+')
            {
                result=oprend1+oprend2;
                push(st1,result);

            }
            else if(postfix[i]=='-')
            {
               result=oprend1-oprend2;
                push(st1,result);
            }
            else if(postfix[i]=='*')
            {
                 result=oprend1*oprend2;

                push(st1,result);
            }
            else if(postfix[i]=='/')
            {
                 result=oprend1/oprend2;
                push(st1,result);
            }
          i++;
        }
    }
    print(*st1);
}
int main()
{
   char *postfix;
     printf("enter the postfix expression");
    gets(postfix);
     stack.size=strlen(postfix);
    creatingstack(&stack);
  evaluation_postfix_expression( postfix,&stack);

    return 0;
}
