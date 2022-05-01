class Solution {
public:
    int countDistinct(vector<int>& v, int k, int p) {
        int n=v.size();
        set<vector<int>>st;
        for(int i=0;i<n;i++)
        {
            vector<int>curr;
            int c{};
            for(int j=i;j<n;j++)
            {
                if(v[j]%p==0) c++;
                if(c>k) break;
                curr.push_back(v[j]);
                            st.insert(curr);

            }
        }
        return st.size();
    }
};