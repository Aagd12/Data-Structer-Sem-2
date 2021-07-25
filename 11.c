#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void printingmultiplication(int a[],int b[],int i,int j)
{
    int carry=0,lenth;
    if(i>j)
    {
        lenth=i+1;
    }
    else if(j>i)
    {
        lenth=j+1;
    }
    else
        lenth=i+1;
    int res[lenth];
    int size=lenth;
    while(lenth)
    {
        if(i>=j?j>0:i>0)
        {
            lenth--,j--,i--;
            if(lenth==1&&(a[i]+b[j]+carry)<10)
            {
                res[lenth]=(a[i]+b[j]+carry)%10;

                carry=(a[i]+b[j]+carry)/10;
                lenth--;
                if(lenth==0)
                {
                    res[lenth]=carry;

                }
                break;
            }
            else if(lenth==1&&(a[i]+b[j]+carry)>10)
            {
                res[lenth]=(a[i]+b[j]+carry)%10;

                carry=(a[i]+b[j]+carry)/10;
                lenth--;
                if(lenth==0)
                {
                    res[lenth]=carry;
                }
                break;
            }
            else
            {
                res[lenth]=(a[i]+b[j]+carry)%10;

                carry=(a[i]+b[j]+carry)/10;
            }
            if(i==0)
            {
                i--;

            }
            else if(j==0)
            {
                j--;
            }
        }
        else
        {
            lenth--,i>=j?i--:j--;

            if(lenth==1&&(i>=j?a[i]:b[j]+carry)<10)
            {
                res[lenth]=((i>=j?a[i]:b[j])+carry)%10;

                carry=((i>=j?a[i]:b[j])+carry)/10;
                lenth--;
                if(lenth==0)
                {
                    res[lenth]=carry;
                }
                break;
            }
            else if(lenth==1&&((i>=j?a[i]:b[j])+carry)>10)
            {
                res[lenth]=((i>=j?a[i]:b[j])+carry)%10;

                carry=((i>=j?a[i]:b[j])+carry)/10;
                lenth--;
                if(lenth==0)
                {
                    res[lenth]=carry;
                }
                break;
            }
            else
            {
                res[lenth]=((i>=j?a[i]:b[j])+carry)%10;
                carry=((i>=j?a[i]:b[j])+carry)/10;
            }

        }
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
    printingmultiplication(a,b,degit1,degit2);


    return 0;
}

