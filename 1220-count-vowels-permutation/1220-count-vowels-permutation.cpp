#define mod 1000000007
#define ll long long
class Solution {
public:
    ll fn(int idx,int n,map<char,vector<char>>&m,char prev,  vector<vector<ll>>&dp)
    {
        if(idx>=n)
        {
            
            return 1;
        }
        
        if(dp[idx][int(prev)-'a']!=-1) return dp[idx][int(prev)-'a'];
        
        ll int call1{};
       
       
             for(auto &i:m[prev])
            {
                call1=(call1+fn(idx+1,n,m,i,dp))%mod;
            }
       
        return dp[idx][int(prev)-'a']=(call1)%mod;
        
       
        
    }
        
    
    int countVowelPermutation(int n) 
    {
     map<char,vector<char>>m;
    m['a'].push_back('e');
    m['e'].push_back('a');
    m['e'].push_back('i');
    m['i'].push_back('a');
    m['i'].push_back('e');
    m['i'].push_back('o');
    m['i'].push_back('u');
    m['o'].push_back('i');
    m['o'].push_back('u');
    m['u'].push_back('a');
        
      vector<vector<ll>>dp(n,vector<ll>(27,-1));
        ll call1{};
       for(auto &i:m)
       {
           call1=(call1+fn(1,n,m,i.first,dp))%mod;
       }
        return call1;
   
    
        
        
        
        
        
        
    }
};