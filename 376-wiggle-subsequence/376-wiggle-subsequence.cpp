class Solution {
public:
    int dp[1001][2];
    int fn(vector<int>&v,int idx,int positive)
    {
        if(idx==v.size()-1) return 1;
        if(dp[idx][positive]!=-1) return dp[idx][positive];
        
        int take=INT_MIN;
            
        if(positive and v[idx+1]-v[idx]>0)
        {
           take=1+fn(v,idx+1,0);
        }
         if(!positive and v[idx+1]-v[idx]<0)
        {
           take=1+fn(v,idx+1,1);
        }
        int nottake=fn(v,idx+1,positive);
        return  dp[idx][positive]=max(nottake,take);
        
    }
    int wiggleMaxLength(vector<int>& v) {
        int n=v.size();
        memset(dp,-1,sizeof(dp));
        return max(fn(v,0,1),fn(v,0,0));
    }
};