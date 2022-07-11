class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t=s;
        std::reverse(begin(t),end(t));
        int m=s.size();
        int n=t.size();
        // vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        vector<int>dp(n+1,0);
        for(int idx1=m-1;idx1>=0;idx1--)
        {
            int prev{};
            for(int idx2=n-1;idx2>=0;idx2--)
            {
                int curr=dp[idx2];
                int call1{},call2{},call3{};
                if(s[idx1]==t[idx2])
                {
                    call1=1+prev;//prev
                }
                else{
                    call2=dp[idx2];
                    call3=dp[idx2+1];

                }
                dp[idx2]=max({call1,call2,call3});
                prev=curr;
            }
        }
        return dp[0];
        
    }
};