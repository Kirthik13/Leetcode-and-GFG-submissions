class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& v1, vector<int>& v2) {
        map<int,int>m;
        for(int i=0;i<v2.size();i++)
        {
            m[v2[i]]=i;
        }
        int n=v2.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and v2[st.top()]<v2[i])
            {
                int idx=st.top();
                st.pop();
                
                ans[idx]=v2[i];
            }
            st.push(i);
        }
        
        vector<int>totans(v1.size(),-1);
        
        for(int i=0;i<v1.size();i++)
        {
            totans[i]=ans[m[v1[i]]];
            
        }
        return totans;
    }
};