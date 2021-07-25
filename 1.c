#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n;
    scanf("%d", &n);
    int a[n][n],c[n][n],d[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                a[i][j] = 1;
            }
            else
                a[i][j] = 0;
        }
    }

    int b[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &b[i]);
    }
    printf("this result for row operation\n");
    int **sum = (int **)calloc(n, sizeof(int *));
    for (int k = 0; k < n; k++)
    {
        sum[k] = (int *)calloc(n, sizeof(int));
    }
    int flag = 0, count = 0, temp = 0,in=0;
    for (int i = 0; i < n - 1; i++)
    {

        if (b[i] == 0 && flag == 0)
        {
            temp++;
            for (int j = 0; j < n; j++)
            {
                printf("%d ", a[i][j]);
                c[in][j]=a[i][j];

            }
            in++;
            printf("\n");
        }
        else if (b[i] == 0 && flag >0)
        {
            if(i==n-2)
            {
                for (int j = 0; j < n; j++)
                {
                    printf("%d ", a[i + 1][j]);
                    c[in][j]=a[i+1][j];
                }
                printf("\n");
                in++;
            }

            if(b[i+1]==0)
            {

                for (int j = 0; j < n; j++)
                {
                    printf("%d ", a[i + 1][j]);
                    c[in][j]=a[i+1][j];
                }
                printf("\n");
                in++;
            }

            temp++;
        }
        else if (b[i] == 1)
        {

            flag++;
            if (count == 0)
            {
                for (int j = 0; j < n; j++)
                {
                    sum[i - count][j] = a[i][j];
                }
            }

            for (int j = 0; j < n; j++)
            {
                sum[i - count][j] = sum[i - count][j] + a[i + 1][j];
            }
            count++;
            if (b[i + 1] == 0)
            {

                for (int j = 0; j < n; j++)
                {
                    printf("%d ", sum[i - count + 1][j]);
                    c[in][j]=sum[i - count + 1][j];
                }
                printf("\n");
                count = 0;
                in++;
            }

            temp++;

            if (count == n - 1)
            {
                for (int j = 0; j < n; j++)
                {
                    printf("%d ", sum[i - count + 1][j]);
                    c[in][j]=sum[i - count + 1][j];

                }
                in++;
            }
            if (temp >= n - 1 && temp != count)
            {

                for (int j = 0; j < n; j++)
                {
                    printf("%d ", sum[i - count + 1][j]);

                    c[in][j]=sum[i - count + 1][j];
                }
                in++;
            }

        }
        if(temp==n-1&&count==0&&flag==0)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", a[i+1][j]);
                c[in][j]=sum[i - count + 1][j];

            }
            in++;
        }
    }
    printf("\nthis result for coloum operation\n");

for(int i=0;i<n;i++){
        for(int j=0;j<in;j++){
          d[i][j]=c[j][i];
        }

}
for(int i=0;i<n;i++){
        for(int j=0;j<in;j++){
          printf("%d ",d[i][j]);
        }
       printf("\n");
}

    return 0;
}

