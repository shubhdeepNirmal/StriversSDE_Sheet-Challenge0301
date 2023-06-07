#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int n = prices.size();
    int maxp=0;
    int mini = prices[0];
    int prof;
    for(int i =1;i<n;i++)
    {
       mini= min(prices[i-1],mini);
       prof= prices[i]-mini;
       maxp= max(prof,maxp);        
    }

    return maxp;
}
