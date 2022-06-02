class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& v) 
    {
        vector<vector<int>>tot;
        for(int i=0;i<v[0].size();i++)
        {
            vector<int>k;
            for(int j=0;j<v.size();j++)
            {
                // swap(v[i][j],v[j][i]);
                k.push_back(v[j][i]);
            }
            tot.push_back(k);

        }
        return tot;
        
    }
};