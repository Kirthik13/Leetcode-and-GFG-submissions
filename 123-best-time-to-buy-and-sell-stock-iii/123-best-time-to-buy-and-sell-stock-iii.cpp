class Solution {
public:
//     int fn(vector<int>&v,int idx,int n,int nos,int buy, vector<vector<vector<int>>>&dp)
//     {
//         if(idx>=n)
//         {
//             return 0;
//         }
//         if(nos==0)
//         {
//             return 0;
//         }
        
//         if(dp[idx][nos][buy]!=-1) return dp[idx][nos][buy];
        
//         int curr_ans;
        
//         if(buy)
//         {
//             int bought=fn(v,idx+1,n,nos,false,dp)-v[idx];
//             int notbought=fn(v,idx+1,n,nos,true,dp);
            
//             curr_ans=max(bought,notbought);

//         }
//         else{
//              int sold=fn(v,idx+1,n,nos-1,true,dp)+v[idx];
//             int notsold=fn(v,idx+1,n,nos,false,dp);
            
//             curr_ans=max(sold,notsold);
//         }
        
//         return dp[idx][nos][buy]=curr_ans;
//     }
    
    
    int fn(vector<int>&v,int idx,int n,int trans,vector<vector<int>>&dp)
    {
        if(idx>=n) return 0;
        if(trans==4)return 0;
        
        if(dp[idx][trans]!=-1) return dp[idx][trans];
        
        int curr_ans;
        
        if(trans%2==0)
        {
            int bought=-v[idx]+fn(v,idx+1,n,trans+1,dp);
            int notbought=fn(v,idx+1,n,trans,dp);
            curr_ans=max(bought,notbought);
      
        }
        else{
            int sold=v[idx]+fn(v,idx+1,n,trans+1,dp);
            int notsold=fn(v,idx+1,n,trans,dp);
            curr_ans=max(sold,notsold);
        }
        return dp[idx][trans]=curr_ans;
    }
    int maxProfit(vector<int>& v) {
        int n=v.size();
        
//         vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(2,0)));
//            vector<vector<int>>dp(3,vector<int>(2,0));
//            vector<vector<int>>curr(3,vector<int>(2,0));

        
//         for(int idx=n-1;idx>=0;idx--)
//         {
//             for(int nos=1;nos<=2;nos++)
//             {
//                 for(int buy=0;buy<=1;buy++)
//                 {
            
//                     // int temp=dp[true];
//                      int curr_ans;
        
//                     if(buy)
//                     {
//                         int bought=dp[nos][false]-v[idx];
//                         int notbought=dp[nos][buy];

//                         curr_ans=max(bought,notbought);

//                     }
//                     else{
//                          int sold=dp[nos-1][true]+v[idx];
//                         int notsold=dp[nos][buy];

//                         curr_ans=max(sold,notsold);
//                     }

//                     curr[nos][buy]=curr_ans;

                    
//                 }
//                 dp=curr;
                
//             }
//         }
        
        
//         // return fn(v,0,n,2,1,dp)
//         return dp[2][1];
        vector<vector<int>>dp(n+1,vector<int>(4,-1));
        return fn(v,0,n,0,dp);
    }
};
