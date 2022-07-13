class Solution {
public:
    // int dp[30001][2];
//     int fn(vector<int>& v,int idx,int n,bool bought)
//     {

//        if(idx>=n)
//        {
        
//           return 0;
//        }
        
//         if(dp[idx][bought]!=-1) return dp[idx][bought];
        
//            if(bought)
//            {
//                int sell=fn(v,idx+1,n,false)+v[idx];
//                int notsell=fn(v,idx+1,n,bought);
//                return dp[idx][bought] =max(sell,notsell);


//            }
//            else{
//                int buy=fn(v,idx+1,n,true)-v[idx];
//                int notbuy=fn(v,idx+1,n,bought);
//                return dp[idx][bought]=max(buy,notbuy);

//            } 
//     }
    int maxProfit(vector<int>& v) {
        int n=v.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,0));
        // vector<int>dp(2,0);
        // vector<int>curr(2,0);
        int dpbuy=0,dpnotbuy=0,currnotbuy{},currbuy;
        
        
        for(int idx=n-1;idx>=0;idx--)
        {
            
               
                   int sell=dpbuy+v[idx];
                   int notsell=dpnotbuy;
                   currnotbuy =max(sell,notsell);


              
                   int buy=dpnotbuy-v[idx];
                   int notbuy=dpbuy;
                   currbuy=max(buy,notbuy);

               
               // prev=temp; 
            dpbuy=currbuy;
            dpnotbuy=currnotbuy;

            // dp=curr;
        }
        
        // int g=fn(v,0,n,false);
        int g=dpbuy;
        return g;
    }
};