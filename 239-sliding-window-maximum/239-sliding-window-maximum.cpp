class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            pq.push({v[i],i});
        }
                    ans.push_back(pq.top().first);

        for(int i=k;i<v.size();i++)
        {
            pq.push({v[i],i});
            while(pq.top().second<=i-k)
            {
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};