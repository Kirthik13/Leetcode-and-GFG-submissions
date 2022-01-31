class Solution {
public:
    int maximumWealth(vector<vector<int>>& v) {
     int ans=INT_MIN;
        for(auto &i:v)
        {
            int c{};
            for(auto &j:i)
            {
                c+=j;
            }
            ans=max(ans,c);
        }
        return ans;
    }
};