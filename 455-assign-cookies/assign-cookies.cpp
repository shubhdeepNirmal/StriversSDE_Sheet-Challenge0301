class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end()); 
        std::sort(s.begin(), s.end()); 
        int contchild= 0;
        int cook =0;
       
        while(cook < s.size()&&contchild< g.size()){
          if(s[cook]>=g[contchild])
          {
           contchild++  ;
          }
          cook++;
        }
        return contchild;
    }
};