#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    sort(arr.begin(),arr.end());
     int last=INT_MIN;
     int currl=0;
     int longest=0;

     for(int i=0;i<n;i++)
     {
         if(arr[i]-1==last)
         {
             currl++;
             last=arr[i];
         }
         else if(arr[i]!=last)
         {
             currl=1;
             last=arr[i];
            
         }
         longest= max(currl,longest);
     }
     

     return longest;
}
