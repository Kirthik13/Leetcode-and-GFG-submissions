class FreqStack {
public:
    unordered_map<int,int>m;
    priority_queue<vector<int>>pq;
    int i=0;
//     FreqStack() {
        
//     }
    
    void push(int val) {
        
        pq.push({++m[val],++i,val});
        // m[val]++;
    }
    
    int pop() {
        int ele=pq.top()[2];
        pq.pop();
        m[ele]--;
        return ele;
        

    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */