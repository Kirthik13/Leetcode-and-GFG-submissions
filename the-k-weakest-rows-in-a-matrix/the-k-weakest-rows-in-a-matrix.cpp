class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& v, int k) {
        priority_queue<pair<int,int>>pq;
        int r=0;
        for(auto i=0;i<v.size();i++)
        {
            
            auto s=accumulate(begin(v[i]),end(v[i]),0);
            pq.push({s,i});
            if(pq.size()>k) pq.pop();
            // r++;
        }
        vector<int>tot;
        while(k--)
        {
            tot.push_back(pq.top().second);
            pq.pop();
        }
        reverse(begin(tot),end(tot));
        return tot;
    }
};