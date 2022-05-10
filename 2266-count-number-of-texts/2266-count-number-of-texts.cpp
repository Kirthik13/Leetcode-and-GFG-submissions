#define mod 1000000007
class Solution {
public:
    unordered_map<int,int>dp;
    int fn(int idx,string &s,vector<int>&keys)
    {
        if(idx==s.size())
        {
            return 1;
        }
        if(dp.find(idx)!=dp.end()) return dp[idx];
        int num=int(s[idx])-'0';
        int but=keys[num];
        // cout<<"num : "<<num<<" but : "<<but<<endl;
        int ans{};
      
        for(int j=idx;j<idx+but&&j<s.size();j++)
        {
            if(s[j]==s[idx])ans=(ans+fn(j+1,s,keys))%mod;
                else break;
        }
        return dp[idx]=ans;
    }
    int countTexts(string s) {
        vector<int>keys={ 0, 0, 3, 3, 3, 3, 3, 4, 3, 4 };
        return fn(0,s,keys);
    }
};