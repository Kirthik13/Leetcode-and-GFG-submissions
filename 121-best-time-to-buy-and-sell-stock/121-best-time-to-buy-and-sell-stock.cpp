class Solution {
public:
    int maxProfit(vector<int>& v) {
        
        int sell{},buy=INT_MAX,pro{},n=v.size();
        if(n==1)
        {
            return 0;
        }
        for(int i=0;i<n;i++)
        {
            // if(buy==INT_MAX)
            // {
            // if(i!=n-1 ){
                buy=min(buy,v[i]);
                // sell=0;
            // }
            // }
            // if(buy<v[i] )
            // {
                // if(buy<v[i]){
                sell=max(sell,v[i]-buy);
                // }
            // }
            // cout<<"buy : "<<buy<<" "<<" sell : "<<sell<<endl;
        }
        return sell;
    }
};