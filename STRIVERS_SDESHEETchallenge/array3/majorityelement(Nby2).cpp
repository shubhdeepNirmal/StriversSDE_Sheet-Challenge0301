#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	int count=0;
	int ele;
	for(int i=0;i<n;i++)
	{  
		if(count==0)
		{
			count=1;
          ele=arr[i];
		}
		else if(arr[i]==ele)
		 {
				count++;
		 }
		else 
		 {
			count--;
		 }		
	}
     
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==ele)
		{
			cnt++;
		}
	}

 if(cnt > n/2)
    {
			return ele;
	}
	return -1;
}
