class Solution {
public:

    int findd(vector<int>& weights,int cap)
    {
        int days=1;
        int load=0;
        int n=weights.size();
        
        for(int i=0;i<n;i++)
        {
            if(load+weights[i]>cap)
            {
                days+=1;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
             
             int low= *max_element(weights.begin(),weights.end());
             int high=0;
             for(int i=0;i<weights.size();i++)
             {
                 high+=weights[i];
             }

            while(low<=high)
            {
                int mid= (low+(high-low)/2);
                int nd=findd(weights,mid);
                if(nd<=days)
                {
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }  

                return low; 
    }
};                                                       