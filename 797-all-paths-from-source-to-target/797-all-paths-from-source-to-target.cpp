class Solution {
public:
    vector<vector<int>>totans;
    
//     void fn(vector<vector<int>>& v,int node,vector<int>&vis,vector<int>&temp,int n)
//     {
//         if(node==n-1)
//         {
//             temp.push_back(node);
//             totans.push_back(temp);
//             temp.pop_back();
            
//             return;
//         }
        
        
//         vis[node]=1;
//         temp.push_back(node);
//         for(auto &it:v[node])
//         {
//             if(!vis[it])
//             {
                
//                 fn(v,it,vis,temp,n);
//             }
//         }
//         if(temp.size()>0) temp.pop_back();
//         vis[node]=0;
        
//     }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& v) {
        int n=v.size();
        
        vector<int>vis(n,0);
       
        
        // fn(v,0,vis,temp,n);
        
        queue<pair<int,vector<int>>>q;
        q.push({0,{}});
        
        while(!q.empty())
        {
            auto node=q.front().first;
            auto temp=q.front().second;
            
            q.pop();
            
            if(node==n-1)
            {
                temp.push_back(node);
                 totans.push_back(temp);
                continue;
            }
            
            temp.push_back(node);
            for(auto &it:v[node])
            {
                q.push({it,temp});
            }
        }
        
        return totans;
    }
};