#include <stdio.h>

int main()
{
    int n,m,sum=0,index,max=0,min=123456789,flag=0;
    printf(" enter row and colom  matrix :\n");
    scanf("%d %d",&n,&m);
    int a[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d",&a[i][j]);

        }
    }
    printf(" print matrix\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf(" %d ",a[i][j]);
        }
        printf("\n");
    }
for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            sum+=a[i][j];
        }
        if(sum>max){
            max=sum;
            index=i+1;

        if(sum<min){
            min=sum;
            flag=i+1;
        }
        sum=0;
    }
}
    max=0,min=12345;
    printf("%d  and %d is the row which have max averageand minium average \n",index,flag);
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            sum+=a[j][i];
        }
        if(sum>max){
            max=sum;
            index=i+1;
        }
         if(sum<min){
            min=sum;
            flag=i+1;
        }

        sum=0;
    }
    printf("%d  and %d is the colom which have max average and minimum avearge",index,flag);
    return 0;
}
