class Solution {
private :
    void solve(vector<vector<int>>&ans,vector<int>&st,vector<int>&nums,int n, int i)
    {
        if (i>=n) {   ans.push_back(st);
            return;
        }
        st.push_back(nums[i]);
        solve(ans,st,nums,n,i+1);
        st.pop_back();
        solve(ans,st,nums,n,i+1);
        return;
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>st;
        solve(ans,st,nums,nums.size(),0);
        return ans;
    }
};