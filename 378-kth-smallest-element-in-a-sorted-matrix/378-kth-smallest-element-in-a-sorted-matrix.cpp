class Solution {
public:
    int fn(vector<vector<int>>&v,int val)
    {
        // int idx=upper_bound(begin(v),end(v),val)-begin(v);
        
        // return idx;
        
        int n=v.size();
        int c=n-1;
        int cnt{};
        
        for(int i=0;i<n;i++)
        {
            while(c>=0 and v[i][c]>val) c--;
            cnt+=(c+1);
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& v, int k) {
        int n=v.size();
        int l=v[0][0];
        int r=v[n-1][n-1];
        
        while(l<r)
        {
            int mid=l+((r-l)/2);
            
            int cnt{};
          
                cnt=fn(v,mid);
            
            
            if(cnt>=k)
            {
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};