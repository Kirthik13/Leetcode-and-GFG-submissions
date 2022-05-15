class Solution {
public:
    int largestCombination(vector<int>& v) {
        int ans=INT_MIN;
        for(int i=0;i<32;i++)
        {
            int cnt{};
            for(auto &num:v)
            {
                cnt+=(num>>i)&1;
            }
            ans=max(cnt,ans);
        }
        return ans==INT_MIN?0:ans;
    }
};