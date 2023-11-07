class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int count=0;
        int n=dist.size();
        vector<float>timing;
        for(int i=0;i<n;i++)
        {
            float timi= ((float)dist[i]/speed[i]);
            timing.push_back(timi);
        }

        sort(timing.begin(),timing.end());
        
        for(int i=0;i<n;i++)
        {
             if(timing[i]<=i) {
                break;
            }
             count++;
        }

        return count;

    }
};