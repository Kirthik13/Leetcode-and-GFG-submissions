class Solution {
public:
    void gameOfLife(vector<vector<int>>& v) {
        int m=v.size();
        int n=v[0].size();
        // vector<vector<int>>v=v2;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int l{},d{};
                if(i-1>=0)
                {
                    if(v[i-1][j]==1 or v[i-1][j]==-2) l++;
                    if(v[i-1][j]==0 or v[i-1][j]==3) d++;
                    if(j-1>=0)
                    {
                        if(v[i-1][j-1]==1 or v[i-1][j-1]==-2) l++;
                        if(v[i-1][j-1]==0 or  v[i-1][j-1]==3) d++;
                    }
                    if(j+1<n)
                    {
                          if(v[i-1][j+1]==1 or v[i-1][j+1]==-2) l++;
                        if(v[i-1][j+1]==0 or v[i-1][j+1]==3) d++;
                    }
                    
                }
                if(j-1>=0)
                {
                    if(v[i][j-1]==1 or v[i][j-1]==-2) l++;
                    if(v[i][j-1]==0 or v[i][j-1]==3) d++;
                        
                }
                if(j+1<n)
                {
                    if(v[i][j+1]==1 or v[i][j+1]==-2) l++;
                    if(v[i][j+1]==0 or v[i][j+1]==3) d++;
                }
                if(i+1<m)
                {
                    if(v[i+1][j]==1 or v[i+1][j]==-2) l++;
                    if(v[i+1][j]==0 or v[i+1][j]==3) d++;
                    if(j-1>=0)
                    {
                        if(v[i+1][j-1]==1 or v[i+1][j-1]==-2) l++;
                        if(v[i+1][j-1]==0 or v[i+1][j-1]==3) d++;
                    }
                    if(j+1<n)
                    {
                        if(v[i+1][j+1]==1 or v[i+1][j+1]==-2) l++;
                        if(v[i+1][j+1]==0 or v[i+1][j+1]==3) d++;
                    }
                }
                if(v[i][j]==1)
                {
                    if(l<2) v[i][j]=-2;
                    // else if(l==2 or l==3) v[i][j]=1;
                    else if(l>3) v[i][j]=-2;
                        
                }
                else if(v[i][j]==0){
                    if(l==3) v[i][j]=3;
                }
                // cout<<" l : "<<l<<" d : "<<d<<endl;
            }
        }
        for(auto &i:v)
        {
            for(auto &j:i)
            {
                if(j==3) j=1;
                else if(j==-2) j=0;
                    
            }
        }
        // return v; 
    }
};