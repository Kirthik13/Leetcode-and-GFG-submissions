class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        int n=v.size();        
        int cy=2;
        stack<int>st;
        vector<int>ans(2*n,-1);
        int idx=(2*n)-1;
        while(cy--)
        {
            for(int i=n-1;i>=0;i--)
            {
                if(st.empty())
                {
                    st.push(v[i]);
                    
                }
                else{
                    while(!st.empty() and st.top()<=v[i])
                    {
                        st.pop();
                    }
                    if(!st.empty())
                    {
                        ans[idx]=st.top();
                        
                    }
                  
                }
                idx--;

                st.push(v[i]);
            }
            
            
       
            
        }
        
        
        
        vector<int> result;
        for(auto i=ans.begin();i!=ans.begin()+(n);i++)
        {
           result.push_back(*i);
        }

        return result;
        
    }
};