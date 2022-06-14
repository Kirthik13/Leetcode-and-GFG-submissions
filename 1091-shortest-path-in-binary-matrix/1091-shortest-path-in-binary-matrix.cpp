class Solution {
public:
    bool isvalid(int &x,int &y,int &n,map<pair<int,int>,int>&vis,vector<vector<int>>&v)
    {
        
        return x>=0 and y>=0 and x<n and y<n and !vis[{x,y}] and !v[x][y];
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& v) {
        vector<pair<int,int>>dir={
            {-1,0},{1,0},{0,-1},{0,1},{-1,1},{1,1},{-1,-1},{1,-1}
        };
        queue<pair<pair<int,int>,int>>q;
        int ans=INT_MAX;
        int n=v.size();
        if(v[0][0]!=0 or v[n-1][n-1]!=0) return -1;
        
                map<pair<int,int>,int>vis;

        q.push({{0,0},1});
        vis[{0,0}]=1;

        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            
            int x=it.first.first;
            int y=it.first.second;
            int steps=it.second;
            
            
            if(x==n-1 and y==n-1)
            {
                ans=min(ans,steps);
            }
            
            for(auto it:dir)
            {
                int dx=x+it.first;
                int dy=y+it.second;
                
                if(isvalid(dx,dy,n,vis,v))
                {
                    q.push({{dx,dy},steps+1});
                    vis[{dx,dy}]=1;
                }
            }
            
        }
        return ans==INT_MAX?-1:ans;
    }
};