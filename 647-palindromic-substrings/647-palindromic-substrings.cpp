class Solution {
public:
    map<pair<int,int>,int>dp;
    int fn(string &s,int l,int r)
    {
        if(l>=r) return 1;
        if(dp.find({l,r})!=dp.end()) return dp[{l,r}];
        return dp[{l,r}]=(s[l]==s[r])?fn(s,l+1,r-1):0;
    }
    int countSubstrings(string s) {
        if(s.size()==1) return 1;
        int m{},n=s.size();
//         for(int i=0;i<s.size();i++)
//         {
//             int l=i,r=i;
//             while(l>=0 and r<s.size() and s[l]==s[r])
//             {
//                 m++;
//                 l--;
//                 r++;
//             }
//             l=i;
//             r=i+1;
//             while(l>=0 and r<s.size() and s[l]==s[r])
//             {
//                 m++;
//                 l--;
//                 r++;
//             }
            
//         }
//         return m;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                m+=fn(s,i,j);
            }
        }
        return m;
    }
};