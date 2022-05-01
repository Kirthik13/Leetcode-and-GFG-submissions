class Solution {
public:
    bool backspaceCompare(string s, string t) {
//         stack<char>s1,s2;
        
//         for(auto &i:s)
//         {
//             if(isalpha(i)) s1.push(i);
//             else
//             {
//                 if(!s1.empty()) s1.pop();
//             }
//         }
//         for(auto &i:t)
//         {
//             if(isalpha(i)) s2.push(i);
//             else
//             {
//                 if(!s2.empty()) s2.pop();
//             }
//         }
      
//         if(s1==s2) return 1;
//         return 0;
        
        int i=s.size()-1,j=t.size()-1;
        while(1)
        {
            int back{};
            while(i>=0 and (back>0 or s[i]=='#'))
            {
                back+=s[i]=='#'?1:-1;
                i--;
            }
             back=0;
            while(j>=0 and (back>0 or t[j]=='#'))
            {
                back+=t[j]=='#'?1:-1;
                j--;
            }
            
            if(i>=0 and j>=0 and s[i]==t[j])
            {
                i--;
                j--;
            }
            else{
                break;
            }
        }
        return i==-1 and j==-1;

    }
};