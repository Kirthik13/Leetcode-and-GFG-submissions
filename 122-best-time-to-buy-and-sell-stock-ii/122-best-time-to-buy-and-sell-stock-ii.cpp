class Solution {
public:
    int dp[30001][2];
    int fn(vector<int>& v,int idx,int n,bool bought)
    {
                // cout<<"idx : "<<idx<<" cur_mon : "<<curr_money<<" cur_prof : "<<curr_profit<<endl;

       if(idx>=n)
       {
        
          return 0;
       }
        
        if(dp[idx][bought]!=-1) return dp[idx][bought];
        
       if(bought)
       {
           int sell=fn(v,idx+1,n,false)+v[idx];
           int notsell=fn(v,idx+1,n,bought);
           return dp[idx][bought] =max(sell,notsell);
           
           
       }
       else{
           int buy=fn(v,idx+1,n,true)-v[idx];
           int notbuy=fn(v,idx+1,n,bought);
           return dp[idx][bought]=max(buy,notbuy);

       } 
    }
    int maxProfit(vector<int>& v) {
        int n=v.size();
        memset(dp,-1,sizeof(dp));
        int g=fn(v,0,n,false);
        return g;
    }
};