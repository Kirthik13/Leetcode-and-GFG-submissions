class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
        
        int n=v[0].size(),m=v.size();
        
        int r=0,c=n-1;
        while(r<m and c>=0)
        {
            // int mid=(+)/2;
            
            if(v[r][c]==target) return 1;
            if(v[r][c]>target) c--;
            else{
                r++;
            }
        }
        return 0;
    }
};