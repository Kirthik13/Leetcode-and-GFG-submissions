class Solution {
public:
    vector<int> topKFrequent(vector<int>& v, int k) {
        map<int,int>m;
        for(auto &i:v)
        {
            m[i]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto &i:m)
        {
            pq.push({i.second,i.first});
        }
        vector<int>tot;
        while(k--)
        {
            tot.push_back(pq.top().second);
            pq.pop();
        }
        return tot;
    }
};