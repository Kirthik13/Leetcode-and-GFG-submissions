class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        
        int m=s.size(),n=t.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int idx1=m-1;idx1>=0;idx1--)
        {
            for(int idx2=n-1;idx2>=0;idx2--)
            {
                int call1{},call2{},call3{};
                if(s[idx1]==t[idx2])
                {
                    call1=1+dp[idx1+1][idx2+1];
                }
                else{
                    call2=dp[idx1+1][idx2];
                    call3=dp[idx1][idx2+1];

                }
                dp[idx1][idx2]=max({call1,call2,call3});
            }

            
        }
        // for(auto &i:dp)
        // {
        //     for(auto &j:i)
        //     {
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        int len=m+n-dp[0][0];
        string ans(len,'.');
        
        int pos1{},pos2{},idx{};
        while(pos1<m and pos2<n)
        {
            if(s[pos1]==t[pos2])
            {
                ans[idx++]=s[pos1++];
                pos2++;
            }
            else{
                if(dp[pos1+1][pos2]>dp[pos1][pos2+1])
                {
                   
                    ans[idx++]=s[pos1];
                    pos1++;

                }
                else{
                    ans[idx++]=t[pos2];
                    pos2++;
                    

                }
            }
        }
         while(pos1<m)
        {
             ans[idx++]=s[pos1++];
         }
         while( pos2<n)
        {
             ans[idx++]=t[pos2++];
         }
        
        return ans;
        
    }
};