class Solution {
public:
    vector<int> topKFrequent(vector<int>& v, int k) {
        vector<int>tot;
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>m;
        for(auto &i:v)
        {
            m[i]++;
        }
        for(auto &i:m)
        {
            pq.push({i.second,i.first});
        }
        while(k--)
        {
            tot.push_back(pq.top().second);
            pq.pop();
        }
        return tot;
    }
};