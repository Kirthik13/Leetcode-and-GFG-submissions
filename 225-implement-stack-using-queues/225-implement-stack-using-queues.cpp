class MyStack {
public:
    queue<int>q1;
    
    MyStack() {
        
    }
    
    void push(int x) {
       if(q1.empty()) q1.push(x);
        else{
            q1.push(x);
            for(int i=0;i<q1.size()-1;i++)
            {
                int g=q1.front();
                q1.pop();
                q1.push(g);
            }
        }
       
    }
    
    int pop() {
        int ans=q1.front();
        q1.pop();
        return ans;
        
    }
    
    int top() {
        int ans=q1.front();
        return ans;
    }
    
    bool empty() {
        if(q1.size()==0) return 1;
        return 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */