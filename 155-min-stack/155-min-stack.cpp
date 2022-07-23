class MinStack {
public:
    
    stack<int>st;
    multiset<int>v;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        v.insert(val);
        
    }
    
    void pop() {

        auto it=v.find(st.top());
        v.erase(it);
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
         return *v.begin();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */