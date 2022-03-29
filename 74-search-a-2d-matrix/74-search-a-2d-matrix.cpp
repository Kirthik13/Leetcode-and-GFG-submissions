class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
        int n=v[0].size(),m=v.size();
        int l=0,r=(n*m)-1;
        
        while(l<=r)
        {
            int mid=(l+r)/2;
            
            if(v[mid/n][mid%n]==target) return 1;
            
            if(v[mid/n][mid%n]<target) l=mid+1;
            else{
                r=mid-1;
            }
                
        }
        return 0;
    }
};