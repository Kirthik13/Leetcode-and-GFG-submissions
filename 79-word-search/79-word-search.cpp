class Solution {
public:
    vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
    bool isvalid(vector<vector<char>>& v,string &s,int idx,int sn,int r,int c,int m,int n, vector<vector<int>>&vis)
    {
        return r>=m or c>=n or c<0 or r<0 or v[r][c]!=s[idx] or vis[r][c]==1;
    }
    bool dfs(vector<vector<char>>& v,string &s,int idx,int sn,int r,int c,int m,int n, vector<vector<int>>&vis)
    {
        if(idx==sn-1)
        {
//             cout<<sn<<endl;
//             cout<<r<<c<<endl;
           
//             cout<<v[r][c]<<endl;
            if(s[idx]==v[r][c]) return 1;
            for(auto &i:dir)
            {
                int newr=i[0]+r;
                int newc=i[1]+c;      

                if(!isvalid(v,s,idx,sn,newr,newc,m,n,vis))
                {
                     return 1;
                }

            }
            return 0;
        }
        if(v[r][c]!=s[idx]) return 0;
        vis[r][c]=1;
        
        for(auto &i:dir)
        {
            int newr=i[0]+r;
            int newc=i[1]+c;      
                          // cout<<newr<<" "<<newc<<endl;

            if(!isvalid(v,s,idx+1,sn,newr,newc,m,n,vis))
            {
                // vis[newr][newc]=1;
                // cout<<s[idx]<<endl;
              // cout<<newr<<" "<<newc<<endl;
                if(dfs(v,s,idx+1,sn,newr,newc,m,n,vis)) return 1;
            }
            
        }
        vis[r][c]=0;
        return 0;
        
        
    }
    bool exist(vector<vector<char>>& v, string s) {
        int sn=s.size();
        int m=v.size(),n=v[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                vector<vector<int>>vis(m,vector<int>(n));
                if(dfs(v,s,0,sn,i,j,m,n,vis)) return 1;
                vis[i][j]=0;
            }
        }
        return 0;
    }
};