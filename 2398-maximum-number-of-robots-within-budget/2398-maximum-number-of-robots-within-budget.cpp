#define ll long long
class Solution {
public:
    int maximumRobots(vector<int>& ct, vector<int>& rt, long long budget) {
        
        priority_queue<pair<ll,ll>>pq;
        
        ll curcost{};
        int i{};
        int ans{};
        for(int j=0;j<ct.size();j++)
        {
            curcost+=rt[j];
            pq.push({ct[j],j});
            
            if(pq.size() and (pq.top().first+(j-i+1)*curcost<=budget))
            {
                ans=max(ans,(j-i+1));
            }
            else{
                
                while(pq.size() and (pq.top().first+(j-i+1)*curcost>budget))
                {
                    curcost-=rt[i];
                
                    if(pq.size() and pq.top().second<=i) pq.pop();
                
                    i++;
                
                    

                }
                
                if(pq.size() and (pq.top().first+(j-i+1)*curcost<=budget))
                {
                    ans=max(ans,(j-i+1));
                }                
            }
            
        }
        
        return ans;
            
            
        
        
        
        
    }
};