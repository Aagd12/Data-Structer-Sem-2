#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int comparestring( char*a,char*b, int size1, int size2)
{
    int count=0,index;
    int j=0;
    int size=size1>size2?size1:size2;
    int low=size1<size2?size1:size2;
    for(int i=0; i<size&&j<low;i++)
    {
        if(count==0)
        {
            j=0;
            if(a[i]==b[j])
            {
                if(count==0)
                {
                    count++;
                    index=i;
                    j++;
                }
            }
        }

       else if(count>0)
        {
            if(a[i]!=b[j])
            {
                i--;
                count=0;
            }
            if(a[i]==b[j]){
                j++;
            }
        }

    }
    if(j<low) return -1;
     else return index;
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
        int output=comparestring(a,b,size1,size2);
                   if(output==-1)
        {
            printf("%d\n",output);
        }
        else  printf("%d\n",output);
    }


