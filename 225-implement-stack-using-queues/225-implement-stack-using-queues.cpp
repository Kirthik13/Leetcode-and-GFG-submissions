class MyStack {
public:
    queue<int>q1;
void rev(queue<int>&q1)
{
    if(q1.size()==0) return;
    if(q1.size()==1)
    {
        // q2.push(q1.front());
        return;
    }
    int val=q1.front();
    q1.pop();
    rev(q1);
    q1.push(val);
}
    MyStack() {
        
    }
    
    void push(int x) {
            q1.push(x);
        
    }
    
    int pop() {
        rev(q1);
        int val=q1.front();
        q1.pop();
        rev(q1);
        return val;
        
    }
    
    int top() {
        rev(q1);
        int val=q1.front();
        rev(q1);
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