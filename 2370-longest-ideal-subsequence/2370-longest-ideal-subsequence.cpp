class Solution {
public:
    int fn(string &s,int idx,int n,int k,char prev,vector<vector<int>>&dp)
    {
        if(idx>=n)
        {
            return 0;
        }
        
        if(dp[idx][int(prev)]!=-1) return dp[idx][int(prev)];
        
        int call1{},call2{};
        if(prev=='-')
        {
            call1=1+fn(s,idx+1,n,k,s[idx],dp);
        }
        else{
            int curr=int(s[idx]);
            int p=int(prev);
            if(abs(curr-p)<=k){
                call1=1+fn(s,idx+1,n,k,s[idx],dp);
            }
        }
        call2=fn(s,idx+1,n,k,prev,dp);
        
        
        
        return dp[idx][int(prev)]=max(call1,call2);
    }
    int longestIdealString(string s, int k) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(150,-1));
        return fn(s,0,n,k,'-',dp);
    }
};