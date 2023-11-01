//memoization
#include <bits/stdc++.h> 
 int mod= 1e9+7;
int solve(int ind, int target, vector<int> &arr , vector<vector<int>>&dp ){
  
  if(ind==0)
  {
      if(target==0&&arr[0]==0) return 2;
      if(target==0||target==arr[0]) return 1;
      return 0;
  }
  if(dp[ind][target]!=-1) return  dp[ind][target];

  int nottake= solve(ind-1,target,arr,dp);

   int take=0;
   if(arr[ind]<=target) solve(ind-1,target-arr[ind],arr,dp);

   return dp[ind][target]=(take+nottake)%mod;



}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int tsum=0;
    for(int i=0;i<n;i++)
    {
        tsum+=arr[i];
    }
    int target= tsum-d;
   
   if(target%2==1 || (target)<0){  
    return 0;
   }
   target=target/2;
   vector<vector<int>> dp(n,vector<int>(target+1,-1));
   return solve(n-1,target,arr,dp);
 
   return 0;
}
/////////////////////////////////////////////


//tabulation
#include <bits/stdc++.h> 
 int mod= 1e9+7;

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int tsum=0;
    for(int i=0;i<n;i++)
    {
        tsum+=arr[i];
    }
    int target= tsum-d;
   
   if(target%2==1 || (target)<0){  
    return 0;
   }
   target=target/2;
   vector<vector<int>> dp(n,vector<int>(target+1,0));
  
  if(arr[0]==0) dp[0][0]=2;
  else dp[0][0]=1;

   

   if(arr[0]!=0&&arr[0]<=target) dp[0][arr[0]]=1;
   
   for(int ind=1;ind<n;ind++)
   {
       for(int targ=0;targ<=target;targ++)
       {
           int nottake= dp[ind-1][targ];

           int take=0;
           if(arr[ind]<=targ) take=dp[ind-1][targ-arr[ind]];
            
            dp[ind][targ]=(nottake+take)%mod;
       }
   }
  return dp[n-1][target];
 
   return 0;
}


/////////////////////

//space-optimization
#include <bits/stdc++.h> 
 int mod= 1e9+7;

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int tsum=0;
    for(int i=0;i<n;i++)
    {
        tsum+=arr[i];
    }
    int target= tsum-d;
   
   if(target%2==1 || (target)<0){  
    return 0;
   }
   target=target/2;
   vector<int>prev(target+1,0);
  
   
  
  if(arr[0]==0) prev[0]=2;
  else prev[0]=1;

   

   if(arr[0]!=0&&arr[0]<=target) prev[arr[0]]=1;
   
   for(int ind=1;ind<n;ind++)
   {
        vector<int>curr(target+1,0);
       for(int targ=0;targ<=target;targ++)
       {
           int nottake= prev[targ];

           int take=0;
           if(arr[ind]<=targ) take=prev[targ-arr[ind]];
            
            curr[targ]=(nottake+take)%mod;
       }
       prev=curr;
   }
  return prev[target];
 
   return 0;
}



