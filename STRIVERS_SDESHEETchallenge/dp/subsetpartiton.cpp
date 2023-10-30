//memoization
bool solve(int ind,int target,vector<int> &arr,vector<vector<int>>&dp)
{
	if(target==0) return dp[ind][target]==true;

	if(ind==0) return dp[ind][target]= (arr[0]==target);

	if(dp[ind][target]!=-1) return dp[ind][target];

	bool nottake= solve(ind-1,target,arr,dp);

	bool take=false;
    if(arr[ind]<=target) take = solve(ind-1,target-arr[ind],arr,dp);

	return dp[ind][target]= take||nottake;
}


int minSubsetSumDifference(vector<int>& arr, int n)
{
	int tsum=0;
	int mini= 1e9;
	for(int i=0;i<arr.size();i++)
	{
		tsum+=arr[i];
	}

	vector<vector<int>> dp(n,vector<int>(tsum+1,-1));

	for(int i=0;i<=tsum;i++)
	{
		bool dummy= solve(n-1,i,arr,dp);
	}

	for(int i=0;i<=tsum;i++)
	{
		if(dp[n-1][i]==true)
		{
			int diff=abs(i-(tsum-i));
			mini=min(mini,diff);
		}
	}

	return mini;
}





//tabulation
#include<bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int tsum=0;
    for(int i=0;i<n;i++){
		tsum+=arr[i];
	}
	
	vector<vector<bool>>dp(n,vector<bool>(tsum+1,false));
	
	for(int ind=0;ind<n;ind++)
	{
	   dp[ind][0]=true;
	}
	
	if(arr[0]<=tsum) dp[0][arr[0]]=true;
	
	for(int ind=1;ind<n;ind++)
	{
		for(int target=1;target<=tsum;target++)
		{
			bool nottake= dp[ind-1][target];
			bool take= false;
			
			if(arr[ind]<=target)take= dp[ind-1][target-arr[ind]];

			dp[ind][target]= take||nottake;
			
		}
	}
	
	int mini= 1e9;
	for(int i=0;i<=tsum;i++){
		if(dp[n-1][i]==true){
		 int diff = abs(i-(tsum-i));
		 mini = min(diff,mini);
		}
	}
    return mini;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();

    cout << "The minimum absolute difference is: " << minSubsetSumDifference(arr, n);

    return 0;
}


//space optimization
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int tsum=0;
	for(int i=0;i<n;i++)
	{
		tsum+=arr[i];
	}

	vector<bool>prev(tsum+1,false);
	vector<bool>curr(tsum+1,false);
	
	prev[0]=true;
	curr[0]=true;
	
	if(arr[0]<=tsum) prev[arr[0]]=true;
	
	for(int ind=1;ind<n;ind++)
	{
		for(int target=1;target<=tsum;target++)
		{
			bool nottake= prev[target];
			
			bool take=false;
			if(arr[ind]<=target) take = prev[target-arr[ind]];
			
			curr[target]= take||nottake;
		}
		prev=curr;
	}

	int mini=1e9;
	
	for(int i=0;i<=tsum;i++)
	{
		if(prev[i]==true)
		{
			int diff= abs(i-(tsum-i));
			mini=min(diff,mini);
		}
	}
	
	return mini;
}

