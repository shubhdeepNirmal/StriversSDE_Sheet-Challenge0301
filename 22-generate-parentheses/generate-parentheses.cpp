class Solution {
private:
  void help(string st,int open,int close,vector<string>&ans){
      if(open==0&&close==0){
          ans.push_back(st);
          return;
      }
      if(open>0){
          help(st+"(",open-1,close,ans);
      }
      if(close>open){
          help(st+")",open,close-1,ans);
      }
  }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        help("",n,n,ans);
        return ans;
    }
};