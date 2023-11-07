class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        priority_queue<float,vector<float>,greater<float>>hp;
        for(int i=0;i<n;i++)
        {
             hp.push((float)dist[i]/speed[i]);
        } 
        int ans=0;
        while(!hp.empty()){
            if(ans>=hp.top()) break;
            ans++;
            hp.pop();
        }
        return ans;
    }
};