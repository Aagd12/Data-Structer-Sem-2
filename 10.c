#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void printingsubstraction(int a[],int b[],int i,int j)
{
    int lenth;
    int  count=0;
    if(i>j)
    {
        lenth=i;
    }
    else if(j>i)
    {
        lenth=j;
    }
    else
        lenth=i;
    int res[lenth];
    int size=lenth;
    if(i<j)
    {
        printf("-");
    }
    if(i==j)
    {
        for(int l=0;l<i;l++){
            if(a[l]<b[l]){
                count++;
                break;
            }
        }
        if(count>0)
        printf("-");
    }
    while(lenth)
    {
        if(i>j)
        {
            if(j)
            {
                lenth--,j--,i--;
                if(a[i]>=b[j])
                {
                    res[lenth]=a[i]-b[j];
                }
                else
                {
                    a[i]+=10;
                    res[lenth]=a[i]-b[j];
                    a[i-1]-=1;
                }

            }
            else
            {
                lenth--,j--,i--;
                res[lenth]=a[i];
            }
        }
        else if(i<j)
        {
            if(i)
            {
                lenth--,j--,i--;
                if(b[j]>=a[i])
                {
                    res[lenth]=b[j]-a[i];
                }
                else
                {
                    b[j]+=10;
                    res[lenth]=b[j]-a[i];
                    b[j-1]-=1;
                }
            }
            else
            {
                lenth--,j--,i--;
                res[lenth]=b[j];

            }

        }
        else
        {
            if(a[0]>b[0]||count==0)
            {
                if(j)
                {
                    lenth--,j--,i--;
                    if(a[i]>=b[j])
                    {
                        res[lenth]=a[i]-b[j];
                    }
                    else
                    {
                        a[i]+=10;
                        res[lenth]=a[i]-b[j];
                        a[i-1]-=1;
                    }

                }
            }
            else
            {
                if(i)
                {
                    lenth--,j--,i--;
                    if(b[j]>=a[i])
                    {
                        res[lenth]=b[j]-a[i];
                    }
                    else
                    {
                        b[j]+=10;
                        res[lenth]=b[j]-a[i];
                        b[j-1]-=1;
                    }
                }
            }
        }

    }

    for(int i=0; i<size; i++)
    {
        printf("%d",res[i]);
    }
    printf("\n");
}

int main()
{
    int degit1,degit2;
    printf("number of degit in 1 and 2 array\n");
    scanf("%d %d",&degit1,&degit2);
    int a[degit1],b[degit2];
    printf("elment of arrys 1\n ");
    for(int i=0; i<degit1; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("elment of arrys 2\n ");
    for(int i=0; i<degit2; i++)
    {
        scanf("%d",&b[i]);
    }
      printf("substract from first to second\n");
    printingsubstraction(a,b,degit1,degit2);
    printf("\nsubstract from second to first\n");
     printingsubstraction(b,a,degit2,degit1);


    return 0;
}

