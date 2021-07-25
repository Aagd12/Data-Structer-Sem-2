#include <stdio.h>

int main()
{
    int n,m;
    printf(" enter row and colom of same size of  sqare matrix < 5* 5(matrix):\n");
    scanf("%d %d",&n,&m);
    int a[n][m];
    char ch='A';
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            a[i][j]=ch++;

        }
    }
    printf(" print matrix\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf(" %c ",a[i][j]);
        }
        printf("\n");
    }
    printf(" digonal matrix\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i==j)
            {
                printf(" %c ",a[i][j]);
            }

        }
    }
    int temp=1;
    while(temp<=n-1)
    {
        for(int i=0; i<n-temp; i++)
        {
            printf(" %c ",a[i][i+temp]);

        }
        for(int i=0; i<n-temp; i++)
        {
            printf(" %c ",a[i+temp][i]);
        }
        temp++;
    }


    return 0;
}
