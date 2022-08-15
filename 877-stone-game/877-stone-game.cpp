class Solution {
public:
    int dp[501][501][2];
    bool fn(vector<int>&v,int l,int alice,int bob,int r,int chance)
    {
        if(l>r)
        {
            return alice>bob;
        }
        
        if(dp[l][r][chance]!=-1)  return dp[l][r][chance];
        
        if(chance==0)
        {
            bool call1=fn(v,l+1,alice+v[l],bob,r,1-chance);
            if(call1) return  dp[l][r][chance]= 1;
            bool call2=fn(v,l,alice+v[r],bob,r-1,1-chance);
            
            return  dp[l][r][chance]= call1 or call2;
            
        }
        else{
             bool call1=fn(v,l+1,alice,bob+v[l],r,1-chance);
            if(call1) return   dp[l][r][chance]= 1;
            
            bool call2=fn(v,l,alice,bob+v[r],r-1,1-chance);
            
            return dp[l][r][chance]=call1 or call2;
        }
    }
    bool stoneGame(vector<int>& v) {
        int n=v.size();
        memset(dp,-1,sizeof(dp));
        return fn(v,0,0,0,n-1,0);
    }
};