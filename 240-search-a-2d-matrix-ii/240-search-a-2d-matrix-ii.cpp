class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
        int m=v.size(),n=v[0].size();
        int r=0,c=n-1;
        while(r<m and c>=0)
        {
            if(v[r][c]==target) return 1;
            if(v[r][c]>target)
            {
                c--;
            }
            else{
                r++;
            }
        }
        return 0;
    }
};