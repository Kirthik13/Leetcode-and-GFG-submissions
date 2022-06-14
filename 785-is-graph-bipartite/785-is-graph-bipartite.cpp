class Solution {
public:
    bool dfs(vector<vector<int>>& v,int node,vector<int>&col)
    {
        for(auto &it:v[node])
        {
            if(col[it]==-1)
            {
                col[it]=1-col[node];
                if(!dfs(v,it,col)) return 0;
            }
            else{
                if(col[it]==col[node]) return 0;
            }
        }
        return 1;
    }        
    bool isBipartite(vector<vector<int>>& v) {
        int n=v.size();
        vector<int>col(n,-1);
        for(int i=0;i<n;i++)
        {
            if(col[i]==-1)
            {
                col[i]=1;
                if(!dfs(v,i,col))
                {
                    return 0;
                }
            }
        }
        return 1;
    }
};