class Solution {
public:
    vector<int> topKFrequent(vector<int>& v, int k) {
        vector<int>tot;
        map<int,int>m;
        for(auto &i:v) m[i]++;
        
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto &i:m)
        {
            pq.push({i.second,i.first});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        
        while(!pq.empty())
        {
            tot.push_back({pq.top().second});
            pq.pop();
        }
        return tot;
    }
};