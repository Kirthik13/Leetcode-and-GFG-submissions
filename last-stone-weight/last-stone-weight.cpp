class Solution {
public:
    int lastStoneWeight(vector<int>& v) {
        priority_queue<int>pq;
        for(auto &i:v)
        {
            pq.push(i);
        }
        while(pq.size()>1)
        {
            int s1=pq.top();
            pq.pop();
      
            if(pq.size()>0){
            if(pq.top()==s1)
            {
                pq.pop();
            }
            
            else{
                int s2=s1-pq.top();
                pq.pop();
                pq.push(s2);
       
            }
            }
        }
        return pq.size()>0?pq.top():0;
        
    }
};