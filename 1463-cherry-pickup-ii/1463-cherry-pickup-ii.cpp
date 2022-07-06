class Solution {
public:
    int cherryPickup(vector<vector<int>>& v) {
        int m=v.size(),n=v[0].size();
          vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
    
    int bc;
    for(int r=m-1;r>=0;r--)
    {
        for(int ac=n-1;ac>=0;ac--)
        {
            for(int bc=n-1;bc>=0;bc--)
            {
                int ans=INT_MIN;
                
                 for(int i=-1;i<=1;i++)
                {
                    for(int j=-1;j<=1;j++)
                    {
                        int new_ac=ac+i;
                        int new_bc=bc+j;
                        int h;
                        if(r+1>=m)
                        {
                            h=0;
                        }
                        else{
                            h=(new_ac>=0 and new_ac<n and new_bc>=0 and new_bc<n)?dp[r+1][new_ac][new_bc]:-1e8;
                        }
                        if(h!=-1e8)
                        {
                            if(ac==bc)
                            {
                                h+=v[r][ac];
                            }
                            else{
                                h+=(v[r][ac]+v[r][bc]);
                            }
                        }
                        ans=max(ans,h);

                    }

                }
               dp[r][ac][bc]=ans;
            }
        }
        
     
    }
    return dp[0][0][n-1];
    }
};