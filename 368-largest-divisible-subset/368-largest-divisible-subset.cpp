class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& v) {
         sort(begin(v),end(v));
    int n=v.size();
   vector<int>dp(n+1,1),hash(n+1,0);
    for(int i=0;i<n;i++) hash[i]=i;
    int maxinos=0,maxidx=0;
    for(int idx=1;idx<n;idx++)
    {
        for(int previdx=idx-1;previdx>=0;previdx--)
        {
           if(v[idx]>=v[previdx] and v[idx]%v[previdx]==0)
           {
               if(dp[idx]<dp[previdx]+1)
               {
                   dp[idx]=dp[previdx]+1;
                   hash[idx]=previdx;
               }
           }
           if(maxinos<dp[idx])
           {
               maxinos=dp[idx];
               maxidx=idx;
           }
        }
    }
    
    vector<int>tot;
    if(hash[maxidx]==maxidx) tot.push_back(v[maxidx]);
    while(hash[maxidx]!=maxidx)
    {
        tot.push_back(v[maxidx]);
        maxidx=hash[maxidx];
        if(hash[maxidx]==maxidx) tot.push_back(v[maxidx]);
    }
    reverse(begin(tot),end(tot));
    
    return tot;
    }
};