bool searchMatrix(vector<vector<int>>& mat, int target) {

int row= mat.size();
int col= mat[0].size();

int l= 0;
int h= row*col-1;

int mid= l+(h-l)/2;

while(l<=h)
{
    int element= mat[mid/col][mid%col];
    if(element==target)
    {
        return true;
    }
    else if(element<target)
    {
        l=mid+1;
    }
    else{
        h=mid-1;
    }
  mid=l+(h-l)/2;
}
return false;        
}
