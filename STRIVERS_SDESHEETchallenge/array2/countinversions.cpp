#include <bits/stdc++.h> 
int cnt = 0;
void merge(long long *arr,int low, int mid , int high)
{
    vector<int> temp;
    int left=low;
    int right= mid+1;

    while(left<=mid&&right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            cnt+=(mid-left+1);
            right++;                                                      
        }
    }

    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
     while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergesort(long long *arr, int low, int high)
{
    if(low>=high) return;
    int mid = (low+high)/2;
    mergesort(arr, low, mid);  
    mergesort(arr, mid + 1, high); 
    merge(arr, low, mid, high);
}


long long getInversions(long long *arr, int n){
   cnt =0;
   mergesort(arr, 0, n-1);
   return cnt;
       
}
