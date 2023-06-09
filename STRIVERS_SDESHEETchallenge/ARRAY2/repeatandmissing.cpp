#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    pair<int,int> ans;
	sort(arr.begin(),arr.end());
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(i<n-1 && arr[i+1]==arr[i] )
        {
           ans.second= arr[i];
        }
        sum+=arr[i];
    }
 sum= (n*(n+1)/2) - (sum-ans.second);
 ans.first= sum;
 return ans; 	
}
