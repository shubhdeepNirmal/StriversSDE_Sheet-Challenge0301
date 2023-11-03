class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
    vector<string> ans;
    int i=0;
    for(auto it:target)
    {
        while(i<it-1)
        {
          ans.push_back("Push");
          i++;
          ans.push_back("Pop");
        }
        ans.push_back("Push");
        i++;
    }
        return ans;
    }
};