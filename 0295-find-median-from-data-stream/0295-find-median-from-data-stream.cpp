class MedianFinder {
public:
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    
    
    MedianFinder() {
    }
    
    void addNum(int k) {
        maxheap.push(k);
        minheap.push(maxheap.top());
        maxheap.pop();
                
        if(maxheap.size()<minheap.size())
        {
            int val=minheap.top();
            minheap.pop();
            
            maxheap.push(val);
            
            
        }
        
    }
    
    double findMedian() {
          return ((maxheap.size()+minheap.size())%2)?maxheap.top():(maxheap.top()+minheap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */