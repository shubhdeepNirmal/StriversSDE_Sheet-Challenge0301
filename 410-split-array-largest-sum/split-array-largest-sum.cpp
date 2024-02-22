class Solution {
public:
    int countpartitions(vector<int> & nums, int maxsum){
        int n= nums.size();
        int partitions=1;
        long long subsum=0;
        for(int i=0;i<n;i++)
        {
            if(subsum+nums[i]<=maxsum){
                subsum+=nums[i];
            }
            else{
                partitions++;
                subsum=nums[i];
            }
        }
        return partitions;
    }
    int splitArray(vector<int>& nums, int k) {
        int low= *max_element(nums.begin(),nums.end());
        int high= accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = low+(high-low)/2;
            int part= countpartitions(nums,mid);

            if(part>k){
                low= mid+1;
            }
            else{
                high=mid-1;
            }
        }
     return low; 
    }
};