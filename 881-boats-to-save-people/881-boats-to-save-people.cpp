class Solution {
public:
    int numRescueBoats(vector<int>& v, int limit) {
        
        sort(rbegin(v),rend(v));
       
        int curr{},ans=0;
        int j=v.size()-1;
        for(int i=0;i<=j;i++)
        {
            
            if(i!=j and v[i]+v[j]<=limit)
            {
                j--;
            }
                        ans++;

            
        }
        return ans;
        
    }
};