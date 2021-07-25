#include <stdio.h>
int main()
{

    int n,m,sum=0,maxrowindex,max=0,min=123456789,maxcoloumindex,minrowindex,mincoloumindex;
    printf(" enter row and colom of matrix :\n");
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
            if(a[i][j]>max)
            {
                max=a[i][j];
                maxrowindex=i, maxcoloumindex=j;
            }
            {
                if(a[i][j]<min)
                {
                    min=a[i][j];
                    minrowindex=i, mincoloumindex=j;
                }
            }
        }
    }
    int temp=a[maxrowindex][maxcoloumindex];
    a[ maxrowindex][ maxcoloumindex]= a[ minrowindex][ mincoloumindex];
    a[ minrowindex][ mincoloumindex]=temp;
    printf("resultant matrix after swaping max->min\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf(" %d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
