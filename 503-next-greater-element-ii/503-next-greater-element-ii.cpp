class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        int n=v.size();        
        int cy=2;
        stack<int>st;
        vector<int>ans(n,-1);
        int idx=2*n-1;
      
            for(int i=2*n-1;i>=0;i--)
            {
                if(st.empty())
                {
                    st.push(v[i%n]);
                    
                }
                else{
                    while(!st.empty() and st.top()<=v[i%n])
                    {
                        st.pop();
                    }
                    if(!st.empty())
                    {
                        ans[idx%n]=st.top();
                        
                    }
                  
                }
                idx--;

                st.push(v[i%n]);
            }
            
            
       
            
        
        
        
        
        // vector<int> result;
        // for(auto i=ans.begin();i!=ans.begin()+(n);i++)
        // {
        //    result.push_back(*i);
        // }

        return ans;
        
    }
};