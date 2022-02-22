class Solution {
public:
    int titleToNumber(string s) {
        long long int res{};
        // for(auto &i:s)
        // {
        //     int d=i-'A'+1;
        //     res*=26;
        //     res+=d;
        // }
        int j=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            res=res+(s[i]-'A'+1)*pow(26,j);
            j++;
        }
        return res;
    }
};