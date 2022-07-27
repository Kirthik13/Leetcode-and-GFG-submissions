class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int c{};
        while(!st.empty() and st.top().first<=price)
        {
            c+=st.top().second;
            st.pop();
        }
        
        st.push({price,c+1});
        return c+1;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */