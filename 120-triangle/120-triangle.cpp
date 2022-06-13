class Solution {
public:
    map<pair<int,int>,int>dp;
    int fn(vector<vector<int>>& v,int i,int j)
    {
        if(i==v.size()-1)
        {
            return v[i][j];
        }
        if(j>=v[i].size())
        {
            return INT_MAX;
        }
        if(dp.find({i,j})!=dp.end()) return dp[{i,j}];
        int l=INT_MAX;
        int r=INT_MAX;
        l=fn(v,i+1,j);
        if(j+1<v[i+1].size())
        {
        r=fn(v,i+1,j+1);
        }
        int retans=min(l,r);
        return dp[{i,j}]=(retans==INT_MAX)?INT_MAX:v[i][j]+retans;
    }
    int minimumTotal(vector<vector<int>>& v) {
        return fn(v,0,0);
    }
};