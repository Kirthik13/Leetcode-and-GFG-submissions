class Solution {
public:
    int scheduleCourse(vector<vector<int>>& v) {
       
      sort(begin(v),end(v),[](auto a,auto b)
           {
               return a[1]<b[1];
           });
        
        priority_queue<int>pq;
        int now{};
        for(int i=0;i<v.size();i++)
        {
            pq.push(v[i][0]);
            now+=v[i][0];
            if(now>v[i][1])
            {
                now-=pq.top();
                pq.pop();
            }
            
        }
        return pq.size();
        
    }
};