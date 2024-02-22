class Solution {
public:
    bool isvalid(vector<int> & nums, int n, int k , int mx){
        int partitions=1;
        long long subsum=0;
        for(int i=0;i<n;i++)
        {
            subsum+=nums[i];
            if(subsum>mx){
                 partitions++;
                 subsum=nums[i];
            }
            if(partitions>k){
                return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n= nums.size();
        int sum=0;
        int low= *max_element(nums.begin(),nums.end());
        int high= accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(isvalid(nums,n,k,mid)){
                 ans=mid;
                 high=mid-1;
            }
            else{
                low= mid+1;
            }
        }
     return ans; 
    }
};