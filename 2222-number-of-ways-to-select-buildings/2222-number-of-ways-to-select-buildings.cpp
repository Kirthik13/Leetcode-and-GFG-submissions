#define ll long long
class Solution {
public:
    long long dp[4][3];
//    ll int fn(string &s,int idx,int n,int nob,int prev)
//     {
//         if(nob==3)
//         {
//             return 1;
//         }
//         if(idx>=n)
//         {
           
//             return 0;
//         }
        
//         if(dp[idx][nob][prev+1]!=-1) return dp[idx][nob][prev+1];
        
//         ll int call1{},call2{};
//         if(prev==-1)
//         {
//             call1=fn(s,idx+1,n,nob+1,int(s[idx])-'0');
//         }
//         else
//         {
//             if(prev==1 and s[idx]=='0')
//             {
//                 call1=fn(s,idx+1,n,nob+1,int(s[idx])-'0');
//             }
//             else if(prev==0 and s[idx]=='1')
//             {
//                 call1=fn(s,idx+1,n,nob+1,int(s[idx])-'0');
                
//             }
//         }
//         call2=fn(s,idx+1,n,nob,prev);
        
//         return dp[idx][nob][prev+1]=call1+call2;
        
        
        
//     }
    long long numberOfWays(string s) {
        int n=s.size();
        memset(dp, 0, sizeof(dp));
        
        for(int idx=n;idx>=0;idx--)
        {
            
                for(int prev=1;prev>=-1;prev--)
                {
                   
                        dp[3][prev+1]=1;
                    
                   
        
                }
            
        }
        
        
        
        
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int nob=2;nob>=0;nob--)
            {
                for(int prev=1;prev>=-1;prev--)
                {
                  
                    ll int call1{},call2{};
                    if(prev==-1)
                    {
                        call1=dp[nob+1][(int(s[idx])-'0')+1];
                    }
                    else
                    {
                        if(prev+1==2 and s[idx]=='0')
                        {
                            call1=dp[nob+1][(int(s[idx])-'0')+1];
                        }
                        else if(prev+1==1 and s[idx]=='1')
                        {
                            call1=dp[nob+1][(int(s[idx])-'0')+1];

                        }
                    }
                    call2=dp[nob][prev+1];
        
                   dp[nob][prev+1]=call1+call2;
                }
            }
        }
        
        return dp[0][0];
        
    }
};