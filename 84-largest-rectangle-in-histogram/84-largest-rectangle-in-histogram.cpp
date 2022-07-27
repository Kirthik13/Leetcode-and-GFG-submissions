class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        
        int n=v.size();
        stack<int>st1;
        int ans=0;
        
        for(int i=0;i<=n;i++)
        {
            while(!st1.empty() and (i==n or v[st1.top()]>=v[i]))
            {
                int height=v[st1.top()];
                int width;
                st1.pop();
                
                if(st1.empty()) width=i;
                
                else width=i-st1.top()-1;
                ans=max(ans,height*width);
            }
            
            st1.push(i);
        }
        
         
     
      
        
        
      
        return ans;
    }
};