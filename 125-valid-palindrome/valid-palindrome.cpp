class Solution {
private:
bool valid(char ch)
{
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'))
    {
        return 1;
    }

    else
    return 0;
}

char tolower(char ch)
{
    if((ch>='a'&&ch<='z')||(ch>='0'&&ch<='9'))
    {
        return ch;
    }

    else{
    char temp= ch-'A'+'a';
    return temp;
    }
}

bool checkpalindrome(string a)
{
    int s=0;
    int e=a.length()-1;

    while(s<=e)
    {
        if((a[s])!=(a[e]))
        {
            return 0;
        }

        else{
            s++;
            e--;
        
        }
    }

    return 1;
}

public:
    bool isPalindrome(string s) {

     int i=0;
     string temp="";

     for(int i=0;i<s.length();i++)
     {
         if(valid(s[i]))
         {
             temp.push_back(tolower(s[i]));
         }
     }

     /* for(int j=0;j<temp.length();j++)
     {
       temp[j]=tolower(temp[j]);
     }
       */
      return checkpalindrome(temp);

        
    }
};