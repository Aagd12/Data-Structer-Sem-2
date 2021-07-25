#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int data;
    int top;
    int size;
    int *array;
} stack;
void creatingstack(struct stack *st)
{
    printf("enter the arry size");
    scanf("%d",&st->size);
    st->top=-1;
    st->array=(int *)calloc(st->size,sizeof(int));
};
int stackisfull(struct stack *st)
{
    if(st->top==st->size-1)return 0;
    else return 1;
};
int stackisempty(struct stack *st)
{
    if(st->top==-1)return 1;
    else return 0;
};
void push(struct stack *st)
{
    int data;
    if(stackisfull(st))
    {
        printf("enter the arry element");
        scanf("%d",&data);
        st->array[++st->top]=data;
    }
    else printf("stack is full\n");
}
void pop(struct stack *st)
{
    int data;
    if(stackisempty(st))
        printf("stack is empty\n");
    else
    {
        data=st->array[st->top--];
        free((void *)st->array[st->top+1]);
    }
}
void print(struct stack st)
{
    int i=0;
    while(i<=st.top)
    {
        printf("%d",st.array[i++]);
    }
    printf("\n");
}
int main()
{
    creatingstack(&stack);
    push(&stack);
    print(stack);
    push(&stack);
    print(stack);
    push(&stack);
    print(stack);
    push(&stack);
    print(stack);
    push(&stack);
    print(stack);
    pop(&stack);
    print(stack);
    pop(&stack);
    print(stack);
    pop(&stack);
    print(stack);
    pop(&stack);
    print(stack);
    pop(&stack);
    print(stack);
    pop(&stack);
    return 0;
}
