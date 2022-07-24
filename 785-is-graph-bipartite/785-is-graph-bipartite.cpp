class Solution {
public:
    bool bfs(vector<vector<int>>& v,int node1,int n, vector<int>&col)
    {
        col[node1]=0;
        
        queue<int>q;
        q.push(node1);
        
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            for(auto &it:v[node])
            {
                if(col[it]==-1)
                {
                    col[it]=1-col[node];
                    q.push(it);
                }
                else if(col[it]==col[node]) return 0;
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
                if(!bfs(v,i,n,col)) return 0;
            }
        }
        return 1;
    }
};
