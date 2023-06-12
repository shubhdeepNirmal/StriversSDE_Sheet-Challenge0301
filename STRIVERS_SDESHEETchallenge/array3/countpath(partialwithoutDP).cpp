#include <bits/stdc++.h> 
   int countpath(int i, int j, int n, int m)
    {
           if(i==(n-1)&&j==(m-1)) return 1;
        if(i>=n||j>=m) return 0;
        else return countpath(i+1,j,n,m) + countpath(i,j+1,n,m); 
   
    }
    int uniquePaths(int m, int n) {
       return countpath(0,0,m,n);
    }
