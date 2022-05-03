class Solution {
public:
    map<pair<int,int>,int>dp;
    bool fn(vector<int>&v,int k,int i)
    {
        if(i==v.size()-1)
        {
            return dp[{k,i}]=1;
        }
        if(dp.find({k,i})!=dp.end())
        {
            return dp[{k,i}];
        }
        for(int j=i+1;j<v.size();j++){
            if(i>0 and (v[j]-v[i]==k or v[j]-v[i]==k-1 or v[j]-v[i]==k+1))
            {
                
                if(fn(v,v[j]-v[i],j)) return dp[{k,i}]=1;
            }
            if(v[j]-v[i]==k )
            {
                
                if(fn(v,v[j]-v[i],j)) return dp[{k,i}]=1;
            }
        }
        return dp[{k,i}]=0;
    }
    bool canCross(vector<int>& v) {
        // memset(dp,-1,sizeof(dp));
        return fn(v,1,0);
    }
};