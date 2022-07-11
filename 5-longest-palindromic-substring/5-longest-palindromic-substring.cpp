class Solution {
public:
    bool ispalin(string &s)
    {
        int l=0,r=s.size()-1;
        while(l<r)
        {
            if(s[l]!=s[r]) return 0;
            l++;r--;
        }
        return 1;
    }
    string longestPalindrome(string s) {
        string t=s;
        std::reverse(begin(t),end(t));
        
        int m=s.size(),n=t.size(),res=INT_MIN;
        string ans;
        vector<int>dp(n+1,0);
    
        for(int idx1=m-1;idx1>=0;idx1--)
        {
            int prev{};
            for(int idx2=n-1;idx2>=0;idx2--)
            {
                int curr=dp[idx2];
                if(s[idx1]==t[idx2])
                {
                    dp[idx2]=1+prev;//prev
                }
                else{
                    dp[idx2]=0;
                }
                if(dp[idx2]>res)
                {
                 
                     string temp=s.substr(idx1,dp[idx2]);
                        if(ispalin(temp)){    //check if common substring is palindromic or not
                             ans=temp;
                        res=dp[idx2];
                        }
                }
                prev=curr;
            }

        }

        return ans;
    }
};