class Solution {
public:
//     int fn(string &s,string &t,int idx1,int idx2,int n,vector<vector<int>>&dp)
//     {
//         if(idx1>=n or idx2>=n)
//         {
//             return 0;
//         }
        
//         if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        
//         int call1{},call2{},call3{};
//         if(s[idx1]==t[idx2])
//         {
//             call1=1+fn(s,t,idx1+1,idx2+1,n,dp);
//         }
//         call2=fn(s,t,idx1+1,idx2,n,dp);
//         call3=fn(s,t,idx1,idx2+1,n,dp);
        
//         return dp[idx1][idx2]=max({call1,call2,call3});
        
        
//     }
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
        int n=s.size();
        string t=s;
        std::reverse(begin(t),end(t));
        vector<int>dp(n+1,0);
        string ans;
        int res=INT_MIN;
        
        for(int idx1=n-1;idx1>=0;idx1--)
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