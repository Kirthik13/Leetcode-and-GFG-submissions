class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        int m=v.size(),n=v[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(v[i][j],v[j][i]);
            }
            std::reverse(begin(v[i]),end(v[i]));
        }
        
        
        
    }
};