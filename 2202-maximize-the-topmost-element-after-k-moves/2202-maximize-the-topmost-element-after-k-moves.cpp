class Solution {
public:
    int maximumTop(vector<int>& v, int k) {
        if(k==0 ) return v.front();
        
        if(k%2!=0 and v.size()==1)
        {
            return -1;
        }
        if(k==1)
        {
            return v[1];
        }
        priority_queue<int>pq;
        
        if(k>v.size())
        {
            return *max_element(begin(v),end(v));
        }
        else if(k==v.size())
        {
            for(int i=0;i<k-1;i++)
            {
                pq.push(v[i]);
            }
            return pq.top();
        }
        for(int i=0;i<k-1;i++)
        {
            pq.push(v[i]);
        }
        return pq.top()>v[k]?pq.top():v[k];
    }
};