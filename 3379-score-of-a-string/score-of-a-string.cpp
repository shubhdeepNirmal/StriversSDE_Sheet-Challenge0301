class Solution {
public:
    int scoreOfString(string s) {
      int n= s.size();
      int ans=0;
      for(int i=0;i<n-1;i++){
        int a = int(s[i])-int(s[i+1]);
        ans+=abs(a);
      }
      return ans;
    }
};