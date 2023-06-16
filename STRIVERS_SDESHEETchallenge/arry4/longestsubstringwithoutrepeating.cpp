#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    int len=0;
    int r=0;
    int l=0;
    int n= input.size();
    unordered_map<char,int> mapp;

    while(r<n)
    {
        if(mapp.count(input[r])!=0) l= max(mapp[input[r]]+1,l);

        mapp[input[r]]=r;

        len = max(len,r-l+1);
        r++;
    }
    return len;
}
