class Solution {
public:
    int maximumUnits(vector<vector<int>>& v, int k) {
        sort(begin(v),end(v),[](auto a,auto b){
            
            return a[1]>b[1];
        });
        int ans{};
        for(auto &i:v)
        {
            int nos=i[0],nou=i[1];
            if(nos<=k)
            {
                ans+=(nos*nou);
                k-=nos;
            }
            else{
                ans+=(k*nou);
                k=0;
            }
            // cout<<"Ans ; "<<ans<<" k : "<<k<<endl;
        }
        return ans;
    }
};