class Solution {
public:
    bool find132pattern(vector<int>& v) {
        if(v.size()<3) return 0;
        stack<int>st;
        int f=INT_MIN;
        for(int i=v.size()-1;i>=0;i--)
        {
            if(f>v[i]) return 1;
            
            while(!st.empty() and st.top()<v[i])
            {
                f=st.top();
                st.pop();
            }
            st.push(v[i]);
           
        }
        return 0;
    }
};