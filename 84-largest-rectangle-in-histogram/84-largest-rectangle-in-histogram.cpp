class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        
        int n=v.size();
        stack<int>st1,st2;
        vector<int>ls(n,-1);
        vector<int>rs(n,n);
        
        for(int i=0;i<n;i++)
        {
            while(!st1.empty() and v[st1.top()]>=v[i])
            {
                st1.pop();
            }
            if(!st1.empty())
            {
                ls[i]=st1.top();
            }
            st1.push(i);
        }
        
         
        for(int i=n-1;i>=0;i--)
        {
            while(!st2.empty() and v[st2.top()]>=v[i])
            {
                st2.pop();
            }
            if(!st2.empty())
            {
                rs[i]=st2.top();
            }
            st2.push(i);
        }
        
        // for(auto &i:ls) cout<<i<<" ";
        // cout<<endl;
        // for(auto &i:rs) cout<<i<<" ";
        
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int width=rs[i]-ls[i]-1;
            int h=v[i];
            ans=max(ans,h*width);
        }
        return ans;
    }
};