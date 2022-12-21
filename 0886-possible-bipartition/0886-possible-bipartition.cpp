class Solution {
public:
//     bool dfs(vector<vector<int>>& v,int node,vector<int>&vis,int col)
//     {
//         vis[node]=col;
//         for(auto &i:v[node])
//         {
//             if(vis[i]==-1)
//             {
//                 if(!dfs(v,i,vis,1-col)) return 0;
//             }
//             else if(vis[node]==vis[i]) return 0;
            
//         }
//         return 1;
//     }
     bool dfs(vector<vector<int>>& v,int nde,vector<int>&vis,int col)
    {
        vis[nde]=col;
//         for(auto &i:v[node])
//         {
//             if(vis[i]==-1)
//             {
//                 if(!dfs(v,i,vis,1-col)) return 0;
//             }
//             else if(vis[node]==vis[i]) return 0;
            
//         }
//         return 1;
         queue<int>q;
         q.push(nde);
         while(!q.empty())
         {
             auto node=q.front();
             q.pop();
             for(auto &i:v[node])
//           {
                if(vis[i]==-1)
                {
                    // if(!dfs(v,i,vis,1-col)) return 0;
                    vis[i]=1-vis[node];
                    q.push(i);
                }
                else if(vis[node]==vis[i]) return 0;
            
             }
         
    return 1;
    }
    bool possibleBipartition(int n, vector<vector<int>>& g) {
        vector<vector<int>>v(n+1);
        for(auto &i:g)
        {
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);            
        }
        
        vector<int>vis(n+1,-1);
        
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==-1)
            {
                if(!dfs(v,i,vis,1)) return 0;
            }
        }
        return 1;
    }
};