class Solution {
public:
    int maxProfit(vector<int>& v) {
            int ans=0;
        int buy=INT_MAX,sell=INT_MIN;
    if(v.size()==1)
    {
        return 0;
    }
        
        
        for(auto &i:v)
        {
             buy=min(buy,i);
            
            // sell=max(sell,i);
            
            ans=max(i-buy,ans);
        }
        return ans;
        
    }
};