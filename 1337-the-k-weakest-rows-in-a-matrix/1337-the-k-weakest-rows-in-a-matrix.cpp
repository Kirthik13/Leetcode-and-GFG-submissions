class Solution {
public:
    int calsoliders(vector<int>&v)
    {
        int l=0,r=v.size()-1,ans=INT_MIN;
        while(l<=r)
        {
            int mid=(l+r)/2;
            
            if(v[mid]==1)
            {
                l=mid+1;
                ans=max(ans,mid+1);
            }
            else{
                r=mid-1;
            }
                
        }
        return ans==INT_MIN?0:ans;
    }
    vector<int> kWeakestRows(vector<vector<int>>& v, int k) {
        priority_queue<pair<int,int>>pq;
        int r=0;
        for(auto i=0;i<v.size();i++)
        {
            
            // auto s=accumulate(begin(v[i]),end(v[i]),0);
            int s=calsoliders(v[i]);
            // cout<<"s : "<<s<<endl;
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