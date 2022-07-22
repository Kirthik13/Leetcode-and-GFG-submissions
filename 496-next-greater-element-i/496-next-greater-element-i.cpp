class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& v1, vector<int>& v2) {
        
        int n=v2.size();
        vector<int>ng(n,-1);
        stack<int>st;
        st.push(v2[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            if(!st.empty())
            {
                while(!st.empty() and st.top()<v2[i]){
                    st.pop();
                }
                if(st.size()>0)
                {
                    ng[i]=st.top();
                }
            }
                st.push(v2[i]);
            
            
        }
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[v2[i]]=i;
        }
        
        vector<int>ans;
        for(int i=0;i<v1.size();i++)
        {
            if(m.find(v1[i])!=m.end())
            {
                ans.push_back(ng[m[v1[i]]]);
            }
            else{
             ans.push_back(-1);
            }    
            
        }
        return ans;
    }
};