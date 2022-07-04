class Solution {
public:
    int candy(vector<int>& v) {
        vector<int>tot(v.size(),1);
        int ans{};
        if(v.size()<=1)
		 return v.size();
        for(int i=1;i<v.size();i++)
        {
            if(v[i-1]<v[i])
            {
                tot[i]=tot[i-1]+1;
            }
        }
        
        for(int i=v.size()-1;i>0;i--)
        {
            if(v[i-1]>v[i])
            {
                tot[i-1]=max(tot[i]+1,tot[i-1]);
            }
             
        }
        for(auto &i:tot) ans+=i;
        return ans;
        
    }
};