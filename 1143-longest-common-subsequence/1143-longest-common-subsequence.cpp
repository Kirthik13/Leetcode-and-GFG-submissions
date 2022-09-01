class Solution {
public:
    // int dp[1001][1001];
    int fn(string &s, string &t,int idx1,int idx2,int m,int n,vector<vector<int>>&dp) 
    {
        if(idx1>=m or idx2>=n) return 0;
        
        if(dp[idx1][idx2]!=-1)  return dp[idx1][idx2];
        
        if(s[idx1]==t[idx2])
        {
            return dp[idx1][idx2]=1+fn(s,t,idx1+1,idx2+1,m,n,dp);
        }
        int call1=fn(s,t,idx1+1,idx2,m,n,dp);
        int call2=fn(s,t,idx1,idx2+1,m,n,dp);
        
        return dp[idx1][idx2]=max(call1,call2);
         
        
        
    }
    int longestCommonSubsequence(string s, string t) {
        
         // if(s.size()<t.size()) swap(s,t);
        int m=s.size(),n=t.size();
        // memset(dp,-1,sizeof(dp));
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return fn(s,t,0,0,m,n,dp);
    }
};

// class Solution {
// public:
//     int fn(string &s1,string &s2,int n,int m,int i1,int i2,vector<vector<int>>&dp)
//     {
//         if(n==i1 or m==i2) return 0;
//         if(dp[i1][i2]!=-1)  return dp[i1][i2];
//         if(s1[i1]==s2[i2])
//         {
//             return dp[i1][i2]=1+fn(s1,s2,n,m,i1+1,i2+1,dp);
//         }
        
//            return dp[i1][i2]=max(fn(s1,s2,n,m,i1+1,i2,dp),fn(s1,s2,n,m,i1,i2+1,dp));
        
//     }
//     int longestCommonSubsequence(string s1, string s2) {
//         if(s1.size()<s2.size()) swap(s1,s2);
//         int n=s1.size(),m=s2.size();
//         vector<vector<int>>dp(1001,vector<int>(1001,-1));
//        return fn(s1,s2,n,m,0,0,dp);
//     }
// };