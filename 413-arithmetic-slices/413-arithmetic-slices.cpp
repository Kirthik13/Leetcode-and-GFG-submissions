class Solution {
public:
    int fn(vector<int>&v,int idx,vector<int>&dp)
    {
        if(idx<2) return 0;
        if(v[idx]-v[idx-1]!=v[idx-1]-v[idx-2]) return 0;
        if(dp[idx]!=-1) return dp[idx];
        return 1+fn(v,idx-1,dp); 
    }
    int numberOfArithmeticSlices(vector<int>& v) {
        if(v.size()<3) return 0;
        vector<int>dp(v.size(),-1);
        int c{};
        for(int i=2;i<v.size();i++){
            
        c+=fn(v,i,dp);
        }
        
        return c;
    }
};
