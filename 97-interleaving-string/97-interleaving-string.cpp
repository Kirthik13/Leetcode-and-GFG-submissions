class Solution {
public:
    // int dp[101][101][201];
//     int fn(int i,int j,int k,string &s1,string &s2,string &s3)
//     {
//         if(i>=s1.size() and j>=s2.size() and k>=s3.size()) return 1;
        
//         if(k>=s3.size()) return 0;
//         if(i>=s1.size() and j>=s2.size()) return 0;

        
//         if(dp[i][j][k]!=-1) return dp[i][j][k];
        
//         int left=0;
//         if(s1[i]==s3[k])
//         {
//             left=fn(i+1,j,k+1,s1,s2,s3);
//         }
//         int right=0;
//         if(s2[j]==s3[k])
//         {
//             right=fn(i,j+1,k+1,s1,s2,s3);
//         }
        
//         return dp[i][j][k]=left or right;
        
//     }
    bool isInterleave(string s1, string s2, string s3) {
      
         if(s1.size() + s2.size() != s3.size()) return false;
        if(s1.size() == 0) return s2 == s3;
        if(s2.size() == 0) return s1 == s3;
        int m=s1.size(),n=s2.size(),p=s3.size();


       
            
        vector<vector<vector<bool>>>dp(m+1,vector<vector<bool>>(n+1,vector<bool>(p+1,false)));
             
        dp[0][0][0]=1;

    
       for(int i = 1;i<=m;i++)
            if(s1[i-1] == s3[i-1]) dp[i][0][i] = dp[i-1][0][i-1];
        for(int j = 1;j<=n;j++)
            if(s2[j-1] == s3[j-1]) dp[0][j][j] = dp[0][j-1][j-1];
        

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int k=1;k<=p;k++)
                {
                    if(i+j == k){
                        dp[i][j][k] = (dp[i-1][j][k-1] and s1[i-1] == s3[k-1]) or 
                            (dp[i][j-1][k-1] and s2[j-1] == s3[k-1]);
                    }
                }
            }
        }
        return dp[m][n][p];
        
        // return fn(0,0,0,s1,s2,s3);
        
        
    }
};