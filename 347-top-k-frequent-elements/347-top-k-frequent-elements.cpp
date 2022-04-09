class Solution {
public:
    vector<int> topKFrequent(vector<int>& v,int k) {
        unordered_map<int,int>m;
        for(auto &i:v)
        {
            m[i]++;
        }
        
        priority_queue<pair<int,int>>pq;
        for(auto &i:m)
        {
            pq.push({i.second,i.first});
        }
        vector<int>v1;
        while(k--)
        {
            v1.emplace_back(pq.top().second);
            pq.pop();
        }
        return v1;
    }
};