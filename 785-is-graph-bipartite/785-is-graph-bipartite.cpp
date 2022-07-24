class Solution {
public:
    bool dfs(vector<vector<int>>& v,int node,int n, vector<int>&col,int prevcol)
    {
        
        
            col[node]=1-prevcol;
        
            for(auto &it:v[node])
            {
                if(col[it]==-1)
                {
                    if(!dfs(v,it,n,col,col[node])) return 0;
                }
                else if(col[it]==col[node]) return 0;
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
                if(!dfs(v,i,n,col,1)) return 0;
            }
        }
        return 1;
    }
};
