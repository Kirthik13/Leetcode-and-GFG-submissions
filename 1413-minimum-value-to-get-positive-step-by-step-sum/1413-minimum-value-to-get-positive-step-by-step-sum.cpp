class Solution {
public:
    int minStartValue(vector<int>& v) {
         int n=v.size();
        int ans=0;
        int curr{};
        for(auto &i:v)
        {
            curr+=i;
            ans=min(ans,curr);
        }
        // ans*=-1;
        return 1-ans;
    }
};