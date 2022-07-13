class Solution {
public:
    int dp[30001][2];
    int fn(vector<int>& v,int idx,int n,int curr_money,bool bought)
    {
                // cout<<"idx : "<<idx<<" cur_mon : "<<curr_money<<" cur_prof : "<<curr_profit<<endl;

//        if(idx==n-1)
//        {
        
//            if(bought) return curr_profit+v[idx]-curr_money;
//            return curr_profit;
//        }
         if(idx>=n)
       {
        
           // if(bought) return curr_profit+v[idx]-curr_money;
           return 0;
       }
        if(dp[idx][bought]!=-1) return dp[idx][bought];
        int curr_res{};
       if(bought)
       {
           int profit=v[idx];
           int sell=fn(v,idx+1,n,curr_money,false)+profit;
           int notsell=fn(v,idx+1,n,curr_money,bought);
           curr_res= max(sell,notsell);
           
           
       }
       else{
           int buy=fn(v,idx+1,n,v[idx],true)-v[idx];
           int notbuy=fn(v,idx+1,n,curr_money,bought);
           curr_res=max(buy,notbuy);

       } 
        return dp[idx][bought]=curr_res;
    }
    int maxProfit(vector<int>& v) {
        int n=v.size();
        memset(dp,-1,sizeof(dp));
        int g=fn(v,0,n,0,false);
        return g;
    }
};