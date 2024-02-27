class Solution {
public:
    int find_max(vector<vector<int>> &g,int col,int row)
{
  int index=-1;
  int maxi=-1;
  for(int i=0;i<row;i++)
  {
    if(g[i][col]>maxi)
    {
      maxi=g[i][col];
      index=i;
    }
  }
  return index;
}

vector<int> findPeakGrid(vector<vector<int>> &g){

  int n=g.size();
  int m=g[0].size();
  int low=0;
  int high=m-1;
  while(low<=high)
  {
    int mid=low+(high-low)/2;
    int maxi_index=find_max(g,mid,n);
    int left=-1;
    if(mid-1>=0)
    {
      left=g[maxi_index][mid-1];
    }
    int right=-1;
    if(mid+1<m)
    {
      right=g[maxi_index][mid+1];
    }

    if(g[maxi_index][mid] > left && g[maxi_index][mid] > right)
    {
      return {maxi_index,mid};
    }
    else if(g[maxi_index][mid] < left)
    {
      high=mid-1;
    }
    else
    {
      low=mid+1;
    }
  }
  return {-1,-1};
    }
};