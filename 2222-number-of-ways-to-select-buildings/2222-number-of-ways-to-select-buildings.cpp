#define ll long long
class Solution {
public:
    long long dp[100003][4][3];
   ll int fn(string &s,int idx,int n,int nob,int prev)
    {
        if(nob==3)
        {
            return 1;
        }
        if(idx>=n)
        {
            if(nob==3)
            {
                return 1;
            }
            return 0;
        }
        
        if(dp[idx][nob][prev+1]!=-1) return dp[idx][nob][prev+1];
        
        ll int call1{},call2{};
        if(prev==-1)
        {
            call1=fn(s,idx+1,n,nob+1,int(s[idx])-'0');
        }
        else
        {
            if(prev==1 and s[idx]=='0')
            {
                call1=fn(s,idx+1,n,nob+1,int(s[idx])-'0');
            }
            else if(prev==0 and s[idx]=='1')
            {
                call1=fn(s,idx+1,n,nob+1,int(s[idx])-'0');
                
            }
        }
        call2=fn(s,idx+1,n,nob,prev);
        
        return dp[idx][nob][prev+1]=call1+call2;
        
        
        
    }
    long long numberOfWays(string s) {
        int n=s.size();
        
        // vector<vector<vector<ll int>>>dp(n,vector<vector<ll int>>(4,vector<ll int>(3,-1)));
      
        memset(dp, -1, sizeof(dp));
        
        return fn(s,0,n,0,-1);
    }
};