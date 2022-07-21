class Solution {
public:
    vector<int> topKFrequent(vector<int>& v, int k) {
        map<int,int>m;
        for(auto &i:v)
        {
            m[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        for(auto &i:m)
        {
            pq.push({i.second,i.first});
            if(pq.size()>k) pq.pop();
        }
        
        vector<int>ans;
        while(!pq.empty())
        {
            auto node=pq.top();
            ans.push_back(node.second);
            pq.pop();
        }
        
        return ans;
      
    }
};