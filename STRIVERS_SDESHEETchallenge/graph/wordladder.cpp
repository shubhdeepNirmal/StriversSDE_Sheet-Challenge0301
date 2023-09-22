class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
      queue<pair<string,int>>q;
      q.push({beginWord,1});

      unordered_set<string>st(wordList.begin(),wordList.end());
      st.erase(beginWord);

      while(!q.empty())
      {
          string currword= q.front().first;
          int num= q.front().second;
          q.pop();
          if(currword==endWord) return num;

          for(int i=0;i<currword.size();i++)
          {
              char original= currword[i];
              for(char ch='a';ch<='z';ch++)
              {
                  currword[i]=ch;
                  if(st.find(currword)!=st.end())
                  {
                      st.erase(currword);
                      q.push({currword,num+1});
                  }
              }
              currword[i]= original;
          }
      }
        return 0;
    }
};
