class Solution {
public:
    void fn( priority_queue<int>&max,priority_queue<int,vector<int>,greater<int>>&min,int el)
    {
        max.push(el);
        min.push(max.top());
        max.pop();
        
        if(max.size()<min.size())
        {
            max.push(min.top());
            min.pop();
        }
    }
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        priority_queue<int>max;
        priority_queue<int,vector<int>,greater<int>>min;
        
        for(auto &i:v1)
        {
            fn(max,min,i);    
        }

        for(auto &i:v2)
        {
            fn(max,min,i);    
        }
        
        int m=max.size();
        int n=min.size();
        
        return ((m+n)&1)?(max.top()*1.0):(max.top()+min.top())/2.0;
        
        
        
    }
};