class Solution {
public:
    map<pair<int,int>,int>dp;
    int fn(int i,int n,string &vow)
    {
        if(n==0) return 1;

        if(i>=5) return 0;
        if(dp.find({i,n})!=dp.end()) return dp[{i,n}];
        int pic=fn(i,n-1,vow);
        int notpic=fn(i+1,n,vow);
        return dp[{i,n}]=pic+notpic;
    }
    int countVowelStrings(int n) {
     string vow="aeiou";
    return fn(0,n,vow);
    }
};