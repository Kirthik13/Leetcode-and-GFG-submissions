class Solution {
public:
    int titleToNumber(string s) {
        long long int res{};
        for(auto &i:s)
        {
            int d=i-'A'+1;
            res*=26;
            res+=d;
        }
        return res;
    }
};