class Solution {
public:
            // map<pair<pair<int,int>,int>,int>dp;
            int dp[10000005];

    int getx(int a,int c)
    {
        return a*100+c;
    }
    int fn(vector<vector<int>>& v,int idx,int n,int c) 
    {
        if(c==2) return 0;
        if(idx>=n)
        {
            if(c==1 or c==2)
            {
                            return 0;
                

            }
            return INT_MIN;
        }
        
        if(dp[getx(idx,c)]!=-1) return dp[getx(idx,c)];
        
        
        vector<int>ans={v[idx][1],INT_MAX,INT_MAX};
        
        int nextidx=upper_bound(begin(v),end(v),ans)-begin(v);
        
        
        int call1{},call2{};
        
            call1=v[idx][2]+fn(v,nextidx,n,c+1);
        
             call2=fn(v,idx+1,n,c);        
        
        return dp[getx(idx,c)]=max(call1,call2);
        
    }
    int maxTwoEvents(vector<vector<int>>& v) {
        sort(begin(v),end(v));
        
       int n=v.size();
        memset(dp,-1,sizeof(dp));
        return fn(v,0,n,0);
    }
};