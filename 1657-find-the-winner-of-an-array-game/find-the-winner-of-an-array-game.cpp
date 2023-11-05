class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
            int maxi=INT_MIN;
            for(int i=0;i<n;i++)
            {
               maxi=max(maxi,arr[i]);
            }

            if(k>=n) return maxi;
            int curr=arr[0];
            int streak=0;
            for(int i=1;i<n;i++)
            {
                int opp=arr[i];
                if(curr>opp) {
                    streak++;
                } 
                else{
                    curr=opp;
                    streak=1;
                }
                if(streak==k||curr==maxi) return curr;
            }  
    
      return -1;
        
    }
};