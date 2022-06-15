class Solution {
public:
    int longestStrChain(vector<string>& v) {
        sort(begin(v),end(v),[](auto a,auto b)
             {
                 return a.size()<b.size();
             });
        int res{};
        unordered_map<string,int>dp;
        for(auto &w:v)
        {
            for(int i=0;i<w.size();i++)
            {
                string pre=w.substr(0,i)+w.substr(i+1);
                dp[w]=max(dp[w],(dp.find(pre)==dp.end())?1:dp[pre]+1);
            }
            res=max(res,dp[w]);
        }
        return res;
    }
};