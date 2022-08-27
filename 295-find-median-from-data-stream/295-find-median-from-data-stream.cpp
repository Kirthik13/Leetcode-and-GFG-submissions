class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>>min;
    priority_queue<int>max;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        max.push(num);
        min.push(max.top());
        max.pop();
        
        if(min.size()>max.size())
        {
            max.push(min.top());
            min.pop();
        }
        
    }
    
    double findMedian() {
        return ((max.size()+min.size())&1)?max.top():(max.top()+min.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */