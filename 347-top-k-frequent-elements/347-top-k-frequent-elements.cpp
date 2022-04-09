class Solution {
public:
    vector<int> topKFrequent(vector<int>& v,int k) {
        unordered_map<int,int>m;
        for(auto &i:v)
        {
            m[i]++;
        }
        
        // priority_queue<pair<int,int>>pq;
        // for(auto &i:m)
        // {
        //     pq.push({i.second,i.first});
        // }
        // vector<int>v1;
        // while(k--)
        // {
        //     v1.emplace_back(pq.top().second);
        //     pq.pop();
        // }
        // return v1;
        
        int n=v.size();
        vector<vector<int>>bucket(n+1);
        
        for(auto &i:m)
        {
            bucket[i.second].emplace_back(i.first);
        }
        
        vector<int>ans;
        for(int i=n;i>=0 and ans.size()<k;i--)
        {
            if(!bucket[i].empty())
            {
                ans.insert(ans.end(),bucket[i].begin(),bucket[i].end());
            }
        }
        return ans;
    }
};