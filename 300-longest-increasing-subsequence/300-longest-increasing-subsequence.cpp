class Solution {
public:
//     int fn(vector<int>&v,int ind,int n,int prev_ind, vector<vector<int>>&dp)
//     {
//        if(ind ==n)return 0;
//         if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];
//         int len = 0+fn(v,ind+1,n,prev_ind,dp);
//         if(prev_ind == -1 || v[ind]>v[prev_ind]){
//              len=max(len,1+fn(v,ind+1,n,ind,dp));
//         }
//         return dp[ind][prev_ind+1]=len;

       
//     }
    
 int fn(vector<int>&v,int idx,int n,int previdx, vector<vector<int>>&dp)
    {
        if(idx>=n) return 0;
        
        if(dp[idx][previdx+1]!=-1) return dp[idx][previdx+1];
        
        int call1{};
        if(previdx==-1 or v[idx]>v[previdx])
        {
            call1=1+fn(v,idx+1,n,idx,dp);
        }
        call1=max(call1,fn(v,idx+1,n,previdx,dp));

        return dp[idx][previdx+1]=call1;
         // return max({call1,call2});

       
    }
    
    int lengthOfLIS(vector<int>& v) {
        // v.insert(v.begin(),INT_MIN);
                int n=v.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
//         vector<int>dp(n+1,0);
//         // vector<int>curr(n+1,0);

        
//         for(int idx=n-1;idx>=1;idx--)
//         {

//             for(int previdx=n-1;previdx>=0;previdx--)
//             {
//                  int call1{},call2{};
//                 if((idx==1 and v[idx]>=v[previdx]) or (idx>1 and v[idx]>v[previdx]))
//                 {
//                     call1=1+dp[idx];
//                 }
//                 call2=dp[previdx];

//                 dp[previdx]=max({call1,call2});
//             }
//             // dp=curr;
//         }
        
//         return dp[0];
        return fn(v,0,n,-1,dp);
    }
};