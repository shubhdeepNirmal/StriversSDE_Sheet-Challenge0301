class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            int t=target-a;
            if(mp.find(t)!=mp.end()){
                ans.push_back(mp[t]);
                ans.push_back(i);
                return ans;
            }
            mp[a]=i;
        }
        return ans;
    }
};