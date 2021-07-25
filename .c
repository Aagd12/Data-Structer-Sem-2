#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void string_hex_sort(char** a,const int len)
{

    for (int i=0; i<len-1; i++)
    {
        for (int j=0; j<len-i-1; j++)
        {
            char *b;
            if(**(a+j)>**(a+j+1))

            {
                b =a[j];
                a[j]=a[j+1];
                a[j+1]=b;
            }

        }

    }
}
void string_hex_revers_sort(char** a,const int len)
{

    for (int i=0; i<len-1; i++)
    {
        for (int j=0; j<len-i-1; j++)
        {
            char *b;
            if(**(a+j)<**(a+j+1))

            {
                b =a[j];
                a[j]=a[j+1];
                a[j+1]=b;
            }

        }

    }
}

void string_lenth_sort(char** a,const int len)
{

    for (int i=0; i<len-1; i++)
    {
        for (int j=0; j<len-i-1; j++)
        {
            char *b;
            if(strlen(a[j])==strlen(a[j+1]))
            {
                if(**(a+j)>**(a+j+1))

                {
                    b =a[j];
                    a[j]=a[j+1];
                    a[j+1]=b;
                }

            }
            if(strlen(a[j])>strlen(a[j+1]))

            {
                b =a[j];
                a[j]=a[j+1];
                a[j+1]=b;
            }

        }

    }
}
void string_distinict_character_sort(char** a,const int len)
{

    int lenth[len];

    int temp[len][100]= {{0}};
    for(int i=0; i<len; i++)
    {
        int size=strlen(a[i]);

        int count=0;

        for(int j=0; j<size-1; j++)
        {

            for(int k=j+1; k<size; k++)
            {

                if((*(*(a+i)+j))==(*(*(a+i)+k)))

                {

                    temp[i][k]=1;

                }

            }
        }

        for(int j=0; j<size; j++)
        {


            if(temp[i][j]==0)
            {
                lenth[i]=count++;
            }
        }

    }
    for (int i=0; i<len-1; i++)
    {
        for (int j=0; j<len-i-1; j++)
         {
            char*b;

            if(lenth[j]>lenth[j+1])
            {

                int d=lenth[j];
                lenth[j]=lenth[j+1];
                lenth[j]=d;
                b =a[j];
                a[j]=a[j+1];
                a[j+1]=b;
            }

        }

    }
    for(int i = 0; i < len; i++)
        printf("%s ka\n", a[i]);
    printf("\n");


     for (int i=0; i<len-1; i++)
    {
        for (int j=0; j<len-i-1; j++)
        {
            char *b;
            if(**(a+0)>**(a+1)&&lenth[0]==lenth[1])

            {
                printf("%s %d",a[j],j);
                b =a[j];
                a[j]=a[j+1];
                a[j+1]=b;
                printf("%s\n",a[j]);
            }

        }

    }
}
int main()
{
    int n;
    scanf("%d", &n);

    char** arr;
    arr = (char**)malloc(n * sizeof(char*));

    for(int i = 0; i < n; i++)
    {
        *(arr + i) =(char*) malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
    }

    string_hex_sort(arr, n);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
    string_hex_revers_sort(arr,n);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
    string_distinict_character_sort(arr,n);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_lenth_sort(arr,n);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
}
