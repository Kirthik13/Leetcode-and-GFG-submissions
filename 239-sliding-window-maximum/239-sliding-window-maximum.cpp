class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
       

        for(int i=0;i<v.size();i++)
        {
            pq.push({v[i],i});
            while(pq.top().second<=i-k)
            {
                pq.pop();
            }
            if(i-k+1>=0){
            ans.push_back(pq.top().first);
            }
        }
        return ans;
    }
};