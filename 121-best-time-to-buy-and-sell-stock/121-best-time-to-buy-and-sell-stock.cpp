class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n=v.size();
        int max_profit=INT_MIN;
        int min_price=v[0];
        for(int i=1;i<v.size();i++)
        {
            int curr_profit=v[i]-min_price;
            max_profit=max(max_profit,curr_profit);
            min_price=min(min_price,v[i]);
        }
        return max_profit>0?max_profit:0;
    }
};