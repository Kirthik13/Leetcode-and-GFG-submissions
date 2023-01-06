class Solution {
public:
    int maxIceCream(vector<int>& v, int k) {
        int n=v.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto &i:v) pq.push(i);
        while(!pq.empty() and k>0)
        {
            auto val=pq.top();
            if(val<=k)
            {
                k-=val;
                pq.pop();

            }
            else{
                break;
            }
        }
        return n-pq.size();
    }
};