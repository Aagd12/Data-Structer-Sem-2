#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    char data;
    int top;
    int size;
    char *array;
} stack;
void creatingstack(struct stack *st)
{
    st->top=-1;
    st->array=(char *)calloc(st->size,sizeof(char));
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
void push(struct stack *st,char data)
{

    if(stackisfull(st))
    {
        st->array[++st->top]=data;
    }
    else printf("stack is full\n");
}
void pop(struct stack *st)
{
    char data;
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
    while(i<=st.top)
    {
        printf("%c",st.array[i++]);
    }
    printf("\n");
}
int isopratend(char in)
{
    if(in=='+'||in=='-'||in=='*'||in=='/'||in=='^')
    {
        return 0;
    }
    else return 1;
}
int isprecedence(char in)
{
    if(in=='^')return 3;
    else if(in=='(')return 0;
    else if(in=='+'||in=='-')
    {
        return 1;
    }
    else return 2;
}

void  converting_infix_to_postfix( struct stack *st, char *in)
{
    char *postfix=(char*)calloc(st->size,sizeof(char));

    int i=0,j=0;
    while(i<st->size)
    {
        if(in[i]=='(')
        {
            push(st,in[i++]);
            print(*st);
        }
        else if(in[i]==')')
        {
            while(st->array[st->top]!='(')
            {
                postfix[j++]=st->array[st->top];
                puts(postfix);
                pop(st);
                print(*st);
            }
            i++;
            pop(st);
            printf("%d",st->top);
            print(*st);
        }
        else if(isopratend(in[i]))
        {
            postfix[j++]=in[i++];
            puts(postfix);

        }
        else
        {
            if(stackisempty(st))
            {
                push(st,in[i++]);
                print(*st);
            }
            else if(isprecedence(in[i])>=isprecedence(st->array[st->top]))
            {
                push(st,in[i++]);
                print(*st);
            }
            else if(isprecedence(in[i])<isprecedence(st->array[st->top]))
            {
                while(isprecedence(in[i])<isprecedence(st->array[st->top])&&st->top>=0)
                {
                    postfix[j++]=st->array[st->top];

                    pop(st);
                    print(*st);
                }
                push(st,in[i]);
                i++;
            }
        }
    }

    while(st->top>=0)
    {

        postfix[j++]=st->array[st->top];
        pop(st);
        puts(postfix);
    }
    printf("postfix expression\n\n\n\n");
    puts(postfix);
}
int main()
{

    char *infix;
    printf("enter the infix expression\n");
    gets(infix);

    stack.size=strlen(infix);
    creatingstack(&stack);
    converting_infix_to_postfix(&stack,infix);
    return 0;
}
