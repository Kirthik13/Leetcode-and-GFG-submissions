class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& v1, vector<int>& v2) {
                int n=v2.size();

        vector<int>tot(v1.size());
        stack<int>st;
        st.push(v2[n-1]);
        vector<int>ans(n,-1);
        
        for(int i=n-2;i>=0;i--)
        {
           
            while(st.size()>0 and st.top()<v2[i])
            {
                st.pop();
            }
            if(st.size()>0) ans[i]=st.top();
            st.push(v2[i]);
        }
        map<int,int>m;
        for(int i=0;i<v2.size();i++)
        {
            m[v2[i]]=i;
        }
        
        for(int i=0;i<v1.size();i++)
        {
            int idx=m[v1[i]];
            tot[i]=ans[idx];
        }
        return tot;
            
        
    }
};