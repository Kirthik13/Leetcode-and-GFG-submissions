class Solution {
public:
    long long subArrayRanges(vector<int>& v) {
        long long ans{};
        
        for(int i=0;i<v.size()-1;i++)
        {
            int minsf=v[i];
            int maxsf=v[i];
            for(int j=i+1;j<v.size();j++)
            {
                minsf=min(minsf,v[j]);
                maxsf=max(maxsf,v[j]);
                ans+=(maxsf-minsf);

            }
        }
        return ans;
    }
};