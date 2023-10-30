//memoization
 int mod =1e9+7;
 int solve(int ind,vector<int>& arr, int k,vector<vector<int>>& dp)
{
	if(k==0) return 1;
	if(ind==0) return arr[0]==k ;
	if(dp[ind][k]!=-1) return dp[ind][k]%mod;

	int nottake= solve(ind-1,arr,k,dp);
	int take=0;
	if(arr[ind]<=k)		take= solve(ind-1,arr,k-arr[ind],dp);
	return dp[ind][k]=(take+nottake)%mod;
}

int findWays(vector<int>& arr, int k)
{
	int n= arr.size();
	vector<vector<int>> dp(n,vector<int>(k+1,-1));
	return solve(n-1,arr,k,dp);
}
//////////////////////////////////////////

//tabulation
int mod=1e9+7;

int findWays(vector<int>& arr, int k)
{
	int n= arr.size();
	
	vector<vector<int>> dp(n,vector<int>(k+1,0));
	
	for(int i=0;i<n;i++)
	{
		dp[i][0]=1;
	}

	if(arr[0]<=k) dp[0][arr[0]]=1;
	
	for(int ind=1;ind<n;ind++)
	{
		for(int target=1;target<=k;target++)
		{
			int nottake= dp[ind-1][target]%mod;
			
			int take=0;
			if(arr[ind]<=target) take=dp[ind-1][target-arr[ind]]%mod;
			
			dp[ind][target]=(take+nottake)%mod;
		}
	}
	return dp[n-1][k]%mod;
}


//space optimization
int mod=1e9+7;

int findWays(vector<int>& arr, int k)
{
	int n= arr.size();
    vector<int> prev(k+1,0);	
	prev[0]=1;
	 
	 if(arr[0]<=k) prev[arr[0]]=1;
	
	for(int ind=1;ind<n;ind++)
	{
		vector<int> curr(k+1,0);
		curr[0]=1;

		for(int target=1;target<=k;target++)
		{
			int nottake= prev[target];
			int take=0;
			if(arr[ind]<=target) take=prev[target-arr[ind]];
			
			curr[target]=(take+nottake)%mod;
		}
		prev=curr;
	}
	return prev[k]%mod;
}





 
