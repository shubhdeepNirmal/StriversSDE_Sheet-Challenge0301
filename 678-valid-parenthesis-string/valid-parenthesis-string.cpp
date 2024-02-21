class Solution {
public:
    bool checkValidString(string s) {
        int n= s.size();
        stack<int> open; 
        stack <int> star;
        for(int i=0;i<n;i++){
            if(s[i]=='(') open.push(i);
            if(s[i]=='*') star.push(i);
            else if(s[i]==')'){
                if(!open.empty()) open.pop();
                else if(!star.empty()) star.pop();
                else  return false;
            }
        }

        while(!open.empty()){
            if(!star.empty()){
                if(open.top()<star.top()){
                    star.pop();
                    open.pop();
                }
                else return false;
            }
            else return false;
        }

        return true;
        
    }
};