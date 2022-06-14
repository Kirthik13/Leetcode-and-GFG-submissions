class Solution {
public:
    bool bfs(vector<vector<int>>& v,int node,vector<int>&col)
    {
        col[node]=1;
        queue<int>q;
        q.push(node);
        
        while(!q.empty())
        {
            int nod=q.front();
            q.pop();
            
        
            for(auto &it:v[nod])
            {
                if(col[it]==-1)
                {
                    col[it]=1-col[nod];
                    q.push(it);
                    // if(!dfs(v,it,col)) return 0;
                }
                else{
                    if(col[it]==col[nod]) return 0;
                }
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
                if(!bfs(v,i,col))
                {
                    return 0;
                }
            }
        }
        return 1;
    }
};