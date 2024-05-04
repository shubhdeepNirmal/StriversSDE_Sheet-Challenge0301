class Solution {
public:
    int findMaxK(vector<int>& nums) {
     
     int ans=-1;
     unordered_set<int>seen;
     for( auto it: nums)
     {
       int number= abs(it);   
        if( number>ans && seen.contains(-it)) ans=number;
      
        seen.insert(it);
     }
     return ans;
                
    }
};