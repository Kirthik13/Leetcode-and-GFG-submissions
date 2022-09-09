class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& v) {
        sort(begin(v),end(v),[](auto &a,auto &b)
             {
                 if(a[0]==b[0]) return a[1]>b[1];
                 return a[0]<b[0];
             });
       
        
        vector<pair<int,int>>st;
                    int cnt{};

        for(int i=0;i<v.size();i++)
        {
            while(!st.empty() and (st.back().first<v[i][0] and st.back().second<v[i][1]))
            {
                // cnt+=st.back().second;
                cnt++;
                st.pop_back();
            }
            
            
            st.push_back({v[i][0],v[i][1]});
            
            
        }
        
        return cnt;
    }
};