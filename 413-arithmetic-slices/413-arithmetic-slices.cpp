class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v) {
        if(v.size()<3) return 0;
        vector<int>dp(v.size(),0);
        for(int i=2;i<v.size();i++)
        {
            if(v[i]-v[i-1]==v[i-1]-v[i-2])
            {
                dp[i]=1+dp[i-1];
            }
        }
        int c{};
        for(auto i:dp)
        {
            c+=i;
        }
        return c;
    }
};
