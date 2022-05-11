#define mod 1000000007
class Solution {
public:
//     unordered_map<int,int>dp;
//     int fn(int idx,string &s,vector<int>&keys)
//     {
//         if(idx==s.size())
//         {
//             return 1;
//         }
        
//         if(dp.find(idx)!=dp.end()) return dp[idx];
        
//         int num=int(s[idx])-'0';
//         int but=keys[num];
//         int ans{};
      
//         for(int j=idx;j<idx+but and j<s.size() and s[j]==s[idx];j++)
//         {
//             ans+=fn(j+1,s,keys);
//             ans%=mod;
//         }
        
//         return dp[idx]=ans;
//     }
    int countTexts(string s) {
        // vector<int>keys={ 0, 0, 3, 3, 3, 3, 3, 4, 3, 4 };
        // return fn(0,s,keys);
        int n=s.size();
        vector<int>dp(n+1);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            dp[i]=dp[i-1];
            char ch=s[i-1];
            if(i>=2 and s[i-2]==ch) dp[i]=(dp[i]+dp[i-2])%mod;
            else continue;
            if(i>=3 and s[i-3]==ch) dp[i]=(dp[i]+dp[i-3])%mod;
            else continue;
    
            if(i>=4 and s[i-4]==ch and (ch=='7' or ch=='9')) dp[i]=(dp[i]+dp[i-4])%mod;
     

        }
        return dp[n]%mod;
    }
};