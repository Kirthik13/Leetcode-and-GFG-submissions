class Solution {
public:
    int dp[101][101][201];
    int fn(int i,int j,int k,string &s1,string &s2,string &s3)
    {
        if(i>=s1.size() and j>=s2.size() and k>=s3.size()) return 1;
        
        if(k>=s3.size()) return 0;
        
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        
        int left=0;
        if(s1[i]==s3[k])
        {
            left=fn(i+1,j,k+1,s1,s2,s3);
        }
        int right=0;
        if(s2[j]==s3[k])
        {
            right=fn(i,j+1,k+1,s1,s2,s3);
        }
        
        return dp[i][j][k]=left or right;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
      
        memset(dp,-1,sizeof(dp));
      return fn(0,0,0,s1,s2,s3);
        
    }
};