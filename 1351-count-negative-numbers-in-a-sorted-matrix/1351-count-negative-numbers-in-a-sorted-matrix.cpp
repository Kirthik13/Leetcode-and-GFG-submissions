class Solution {
public:
    int countNegatives(vector<vector<int>>& v) {
        int ans{};
        for(auto &i:v)
        {
            auto idx=upper_bound(rbegin(i),rend(i),-1)-i.rbegin();
            // cout<<idx<<endl;
            ans+=(idx);
        }
        return ans;
    }
};