class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& v1, vector<int>& v2, int k) {
        int cnt{},m=v1.size(),n=v2.size(),i{},j{};
        vector<vector<int>>totans;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        for(int i=0;i<m;i++)
        {
            pq.push({v1[i]+v2[0],{i,0}});
        }
        
        while(!pq.empty() and k--)
        {
            auto node=pq.top();
            pq.pop();
            
            int x=node.second.first;
            int y=node.second.second;
            
            totans.push_back({v1[x],v2[y]});
            
            if(y!=n-1)
            {
                pq.push({v1[x]+v2[y+1],{x,y+1}});
            }
            
            
            
        }
        
        
        return totans;
        
    }
};