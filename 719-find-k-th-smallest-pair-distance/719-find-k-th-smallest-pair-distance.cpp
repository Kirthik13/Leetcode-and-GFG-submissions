class Solution {
public:
    bool cando(vector<int>& v, int dist,int k)
    {
        int j=1,total{},n=v.size();
        for(int i=0;i<v.size();i++)
        {
            while(j<n and v[j]-v[i]<=dist) j++;
            j--;
            total+=(j-i);
        }
        return total>=k;
    }
    int smallestDistancePair(vector<int>& v, int k) {
        sort(begin(v),end(v));
        int l=0,r=1e6;
        
        vector<int>tot;
        while(l<r)
        {
            int mid=l+((r-l)/2);
            
            if(cando(v,mid,k))
            {
                tot.push_back(mid);
                r=mid;
                
            }
            else{
                l=mid+1;
            }
        }
        
        return l;
        
    }
};