#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int comparestring( char*a,char*b, int size1, int size2)
{
    int size=size1<size2?size1:size2;
    for(int i=0; i<size; i++)
    {
        if(a[i]==b[i])
        {
            continue;
        }
        else return 0;
        return 1;
    }
}
int main()
{
    char a[100];
    char b[100];
    printf("enter first string:\n");
    gets(a);
    printf("enter second string:\n");
    gets(b);
    int size1=strlen(a);
    int size2=strlen(b);
    if(comparestring(a,b,size1,size2))
    {
        printf("string is prefix:\n");
    }
    else  printf("string is not prefix:\n");
}

