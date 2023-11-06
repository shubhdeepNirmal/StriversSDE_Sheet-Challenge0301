class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        stack<int>st;
        int maxi=INT_MIN;
        st.push(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            int ele=nums[i];
            int topp=st.top();
            if(ele>topp) maxi=max(maxi,ele-topp);
            else if(ele<topp) st.push(ele);
        }
        if(maxi==INT_MIN) return -1;
        return maxi;
    }
};