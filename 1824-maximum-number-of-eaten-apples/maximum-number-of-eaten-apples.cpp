#define pii pair<int,int> 

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int ans=0;
        int n=apples.size();
        int i=0;
        priority_queue<pii, vector<pii>,greater<pii>>pq;
        for(;i<n;++i)
        {
            if(apples[i]){
                pq.push({i+days[i],apples[i]});
            }
            while(!pq.empty()&&pq.top().first<=i){
                pq.pop();
            }
            if(pq.empty()){
                continue;
            }
            pii now=pq.top();
            pq.pop();
            if(now.second>1){
                pq.push({now.first,now.second-1});
            }
            ++ans;
        }
        while(!pq.empty()){
            while(!pq.empty()&&pq.top().first<=i){
                pq.pop();
            }
            if(pq.empty()){
                break;
            }
            ++i;
            pii now=pq.top();
            pq.pop();
            if(now.second>1){
                pq.push({now.first,now.second-1});
            }
            ++ans;
        }
        return ans;
    }
};