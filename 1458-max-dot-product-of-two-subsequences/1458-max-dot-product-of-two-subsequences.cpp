class Solution {
public:
    int fn(vector<int>& v1, vector<int>& v2,int i,int j,int m,int n,    vector<vector<int>>&dp) 
    {
        if(i>=m or j>=n)
        {
            return INT_MIN;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int take1=fn(v1,v2,i+1,j,m,n,dp);
        int take2=fn(v1,v2,i,j+1,m,n,dp);
        int leave=fn(v1,v2,i+1,j+1,m,n,dp);
        
        int take12=(leave<0?0:leave)+(v1[i]*v2[j]);
        
        return dp[i][j]=max({take1,take2,take12,leave});
        
                

        
    }
    int maxDotProduct(vector<int>& v1, vector<int>& v2) {
        int m=v1.size(),n=v2.size();
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        
        int ans=fn(v1,v2,0,0,m,n,dp);
        
//         if(ans==0)
//         {
//             int a=*min_element(begin(v1),end(v1));
//             int b=*max_element(begin(v1),end(v1));
//             int c=*min_element(begin(v2),end(v2));
//             int d=*max_element(begin(v2),end(v2));
            
            
//             ans=max(a*d,b*c);
//         }
        return ans;
    }
};