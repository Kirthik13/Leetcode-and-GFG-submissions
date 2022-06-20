class Solution {
public:
    int fn(string &s,int &k,int idx,int score,int &n,vector<int>&dp,int power)
    {
        if(idx<0)
        {
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];
        int l=0,r=0;
        if(s[idx]=='1')
        {
            if(k>=score+pow(2,power))
            {
                r=1+fn(s,k,idx-1,score+pow(2,power),n,dp,power+1); 
            }
        }
        else{
             r=1+fn(s,k,idx-1,score,n,dp,power+1);
        }
        l=fn(s,k,idx-1,score,n,dp,power);
        return dp[idx]=max(l,r);
    }
    int longestSubsequence(string s, int k) {
        int n=s.size();
        vector<int>dp(n,-1);
        return fn(s,k,n-1,0,n,dp,0);
        
    }
};