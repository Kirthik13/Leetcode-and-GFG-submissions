class Solution {
public:
    bool fn(string &s,string &t,int idx1,int idx2,int m,int n,vector<vector<int>>&dp)
{
    if(idx1>=m and idx2>=n) return 1;
    if(idx1>=m )
    {
        if(t[idx2]=='*')   return fn(s,t,idx1,idx2+1,m,n,dp);

        // if(idx2==n-1 and t[idx2]=='*') return 1;
        return 0;
    }
    if(idx2>=n) return 0;
    
    if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
    
//     if(idx2>=n or idx1>=m) return 0; 
    if(t[idx2]=='?' or s[idx1]==t[idx2])
    {
        return fn(s,t,idx1+1,idx2+1,m,n,dp);
    }
    if(s[idx1]!=t[idx2] and t[idx2]!='*') return 0;
    
    bool call1=fn(s,t,idx1+1,idx2,m,n,dp);
    bool call2=fn(s,t,idx1,idx2+1,m,n,dp);
    bool call3=fn(s,t,idx1+1,idx2+1,m,n,dp);
    
    return dp[idx1][idx2]=call1 or call2 or call3;
}
    bool isMatch(string s, string t) {
        int m=s.size(),n=t.size();
    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    return fn(s,t,0,0,m,n,dp);
    }
};