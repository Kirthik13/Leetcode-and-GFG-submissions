class Solution {
public:
    int dp[101][10001];
    bool fn(string s,string t,int idx1,int idx2)
    {
        if(idx1==s.size())
        {
            return 1;
        }
        if(idx2==t.size())
        {
            if(idx1==s.size()) return 1;
            return 0;
        }
        if(dp[idx1][idx2]!=-1)
        {
            return dp[idx1][idx2];
        }
                bool g=0;

        if(s[idx1]==t[idx2])
        {
            return dp[idx1][idx2]=fn(s,t,idx1+1,idx2+1);
        }
        else{
        g=fn(s,t,idx1,idx2+1);
        }
        return dp[idx1][idx2]=g;
    }
    bool isSubsequence(string s, string t) {
    if(s.size()==0)
    {
        // if(t.size()==0) return 1;
        return 1;
    }
    if(t.size()==0)
    {
        if(s.size()==0) return 1;
        return 0;
    }
        memset(dp,-1,sizeof(dp));
       return fn(s,t,0,0);
    }
};