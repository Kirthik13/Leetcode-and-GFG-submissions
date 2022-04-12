class Solution {
public:
    void gameOfLife(vector<vector<int>>& v2) {
        int m=v2.size();
        int n=v2[0].size();
        vector<vector<int>>v=v2;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int l{},d{};
                if(i-1>=0)
                {
                    if(v[i-1][j]==1) l++;
                    if(v[i-1][j]==0) d++;
                    if(j-1>=0)
                    {
                        if(v[i-1][j-1]==1) l++;
                        if(v[i-1][j-1]==0) d++;
                    }
                    if(j+1<n)
                    {
                          if(v[i-1][j+1]==1) l++;
                        if(v[i-1][j+1]==0) d++;
                    }
                    
                }
                if(j-1>=0)
                {
                    if(v[i][j-1]==1) l++;
                    if(v[i][j-1]==0) d++;
                        
                }
                if(j+1<n)
                {
                    if(v[i][j+1]==1) l++;
                    if(v[i][j+1]==0) d++;
                }
                if(i+1<m)
                {
                    if(v[i+1][j]==1) l++;
                    if(v[i+1][j]==0) d++;
                    if(j-1>=0)
                    {
                        if(v[i+1][j-1]==1) l++;
                        if(v[i+1][j-1]==0) d++;
                    }
                    if(j+1<n)
                    {
                        if(v[i+1][j+1]==1) l++;
                        if(v[i+1][j+1]==0) d++;
                    }
                }
                if(v[i][j]==1)
                {
                    if(l<2) v2[i][j]=0;
                    else if(l==2 or l==3) v2[i][j]=1;
                    else if(l>3) v2[i][j]=0;
                        
                }
                else if(v[i][j]==0){
                    if(l==3) v2[i][j]=1;
                }
                // cout<<" l : "<<l<<" d : "<<d<<endl;
            }
        }
        // return v; 
    }
};