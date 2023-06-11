#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    vector<int> ans;
    int n= arr.size();
    unordered_map<int,int> mapp;

    for(int i=0;i<n;i++)
    {
        mapp[arr[i]]++;
    }
    for(auto it: mapp)
    {
        if(it.second> floor(n/3))
        {
            ans.push_back(it.first);
        }
        if(ans.size()==2)
        {
            return ans;
        }
    }
 return ans;
}
