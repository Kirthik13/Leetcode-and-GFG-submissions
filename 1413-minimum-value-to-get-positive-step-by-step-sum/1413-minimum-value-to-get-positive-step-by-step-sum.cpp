class Solution {
public:
    int minStartValue(vector<int>& v) {
         int n=v.size();
        int ans=INT_MAX;
        int curr{};
        for(auto &i:v)
        {
            curr+=i;
            ans=min(ans,curr);
        }
        ans*=-1;
        // deb(ans);
        if(ans>0)
        {
            return ans+1;
        }
        // else{
            return 1;
        // }
    }
};