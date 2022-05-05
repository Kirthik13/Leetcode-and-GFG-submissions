class MyStack {
public:
    queue<int>q1;

    MyStack() {
        
    }
    
    void push(int x) {
            q1.push(x);
       
        int z=q1.size();
        z--;
        while(z--)
        {
            int v=q1.front();
            q1.pop();
            q1.push(v);
        }
      
    }
    
    int pop() {
        int val=q1.front();
        q1.pop();
        return val;
        
    }
    
    int top() {
        int val=q1.front();
        return val;
    }
    
    bool empty() {
        if(q1.size()>0) return 0;
        return 1;
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