class Solution {
public:
    string makeGood(string s) {
        vector<char>st;
        for(auto &i:s)
        {
            char ch;
            int f=0;
            if(isupper(i) and st.size()>0)
            {
                ch=char(i)+32;
                // cout<<ch<<" "<<st.back();
            
            
                if(st.back()==ch)
                {
                    // cout<<st.back()<<" "<<i<<endl;
                    st.pop_back();
                }
                  else{
                    st.push_back(i);
                 }
                f=1;
            }
            if(islower(i) and st.size()>0)
            {
              ch=char(i)-32;
                // cout<<ch<<" "<<st.back();
            
            
                if(st.back()==ch)
                {
                    // cout<<st.back()<<" "<<i<<endl;
                    st.pop_back();
                }  
                else{
                    st.push_back(i);
                }
                
                f=1;
                
            }
            
            if(!f)
            {
                                st.push_back(i);

            }
          
        }
        
        string ans;
        for(auto &i:st)
        {
            ans.push_back(i);
        }
        return ans;
        
    }
};