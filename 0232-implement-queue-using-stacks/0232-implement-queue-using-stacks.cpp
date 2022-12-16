class MyQueue {
public:
    stack<int>st1;
    stack<int>st2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(!st2.empty())
        {
            int ans=st2.top();
            st2.pop();
            return ans;
        }
        else{
            // swap(st1,st2);
             while(!st1.empty()){
            int x=st1.top();
            st1.pop();
            st2.push(x);
        }
            int ans=st2.top();
            st2.pop();
            return ans;            
        }
        
    }
    
    int peek() {
          if(!st2.empty())
        {
            int ans=st2.top();
            return ans;
        }
        else{
            // swap(st1,st2);
             while(!st1.empty()){
                int x=st1.top();
               st1.pop();
                st2.push(x);
        }
            int ans=st2.top();
            return ans;            
        }
    }
    
    bool empty() {
        if(st1.size()==0 and st2.size()==0) return 1;
        return 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */