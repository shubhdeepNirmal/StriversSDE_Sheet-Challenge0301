class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
    vector<string> ans;
    int m=1;

    for(int i=0;i<target.size();i++)
    {
        if(target[i]==m){
            ans.push_back("Push");
            m++;
        }
        else{
            while(m<target[i])
            {
                ans.push_back("Push");
                ans.push_back("Pop");
                m++;
            }
        }

        if(target[i]==m) {
            ans.push_back("Push");
            m++;
        }

    }

     return ans;
    }
   
};