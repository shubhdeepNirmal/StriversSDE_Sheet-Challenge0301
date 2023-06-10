#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
   vector<int>visited(arr.size(),0);
        for(int i=0;i<n;i++)
        {
            visited[arr[i]]++;
            if(visited[arr[i]]==2) return arr[i];
        }
        return -1; 
  
  return 0;
}
