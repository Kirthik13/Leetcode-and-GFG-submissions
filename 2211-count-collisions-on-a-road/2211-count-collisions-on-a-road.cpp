class Solution {
public:
    int countCollisions(string s) {
        int c{};
        int n=s.size();
        
        // int i{};
        // int carfromright{};
        // while(i<n and s[i]=='L') i++;
        // for(;i<n;i++)
        // {
        //     if(s[i]=='R') ++carfromright;
        //     else{
        //         c+=(s[i]=='S')?carfromright:carfromright+1;
        //         carfromright=0;
        //     }
        // }
        
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            if(st.empty()) st.push(s[i]);
            else if(st.top()=='S' and s[i]=='L') c++;
            else if(st.top()=='R' and s[i]=='L')
            {
                s[i]='S';
                c+=2;
                st.pop();
                i--;
            }
            else if(st.top()=='R' and s[i]=='S')
            {
                s[i]='S';
                c++;
                st.pop();
                i--;
            }
            else{
                st.push(s[i]);
            }
        }
        return c;
        
    }
};