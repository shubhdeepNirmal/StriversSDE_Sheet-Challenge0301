#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int rows=0;
    int cols=0;
    int prev;
    int curr;

    while(rows<n&&cols<m)
    {
        if(rows==n-1||cols==m-1)
        {
            break;
        }

        prev= mat[rows+1][cols];

        for(int i=cols;i<m;i++)
        {
            curr=mat[rows][i];
            mat[rows][i]=prev;
            prev=curr;
        }
        rows++;

        for(int i=rows;i<n;i++)
        {
            curr=mat[i][m-1];
            mat[i][m-1]=prev;
            prev=curr;

        }
        m--;

        if(rows<n)
        {
            for(int i=m-1;i>=cols;i--)
            {
                curr=mat[n-1][i];
                mat[n-1][i]=prev;
                prev=curr;
            }
                   
        }
         n--;

        if(cols<m)
        {
            for(int i=n-1;i>=rows;i--)
            {
                curr=mat[i][cols];
                mat[i][cols]=prev;
                prev=curr;
            }
        }
        cols++;
    }

}
