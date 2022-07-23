class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        for(int i=0;i<v.size();i++)
        {
            while(!pq.empty() and pq.top().second<=i-k)
            {
                pq.pop();
            }
            
            pq.push({v[i],i});
            if(i>=k-1)
            {
                ans.push_back(pq.top().first);
            }
                
        }
        return ans;
    }
};