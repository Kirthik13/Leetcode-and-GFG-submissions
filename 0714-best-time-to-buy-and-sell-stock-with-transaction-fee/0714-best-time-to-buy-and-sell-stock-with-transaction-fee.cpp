class Solution {
public:
    int dp[100001][2];
    int fn(vector<int>& v,int idx,int n, int &fee,bool canbuy) 
    {
        if(idx>=n) return 0;
        if(dp[idx][canbuy]!=-1) return dp[idx][canbuy];
        int ans1=0,ans2{},ans3{};
        ans3=fn(v,idx+1,n,fee,canbuy);
        
        if(canbuy)
        {
            ans1=fn(v,idx+1,n,fee,0)-v[idx];
            return dp[idx][canbuy]=max(ans1,ans3);
        }
        
        ans2=fn(v,idx+1,n,fee,1)+(v[idx]-fee);

        return dp[idx][canbuy]=max(ans2,ans3);
    }
    int maxProfit(vector<int>& v, int fee) {
        bool canbuy=1;
        int n=v.size();
        memset(dp,0,sizeof(dp));
        
        
            for(int idx=n-1;idx>=0;idx--)
            {
                for(int canbuy=0;canbuy<=1;canbuy++)
                {
                    int ans1=0,ans2{},ans3{};
                    ans3=dp[idx+1][canbuy];

                    if(canbuy)
                    {
                        ans1=dp[idx+1][0]-v[idx];
                        dp[idx][canbuy]=max(ans1,ans3);
                    }
                    else{
                        ans2=dp[idx+1][1]+(v[idx]-fee);

                        dp[idx][canbuy]=max(ans2,ans3);
                    }
                }
            }
        
        // return fn(v,0,n,fee,canbuy);
        return dp[0][1];
    }
};