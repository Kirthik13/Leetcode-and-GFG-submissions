class Solution {
public:
    bool find132pattern(vector<int>& v) {
        
        vector<int>st;
        int n=v.size();
        vector<int>mins(n,0);
        
        for(int i=0;i<n;i++)
        {
           if(i==0)
           {
               mins[i]=0;
           }
           else{
               if(v[i]<v[mins[i-1]])
               {
                   mins[i]=i;
               }
               else
               {
                   mins[i]=mins[i-1];
               }
           }
            
            
            
            while(!st.empty() and v[st.back()]<=v[i])
            {
                st.pop_back();
            }
            if(st.size()>0)
            {
                                if(v[mins[st.back()]]<v[i]) return 1;

            }
            st.push_back(i);
        }
        return 0;
        
    }
};