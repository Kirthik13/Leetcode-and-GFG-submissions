class Solution {
public:
    int mem[30001];
    int dp(int i,string &s)
    {
        if(i<=0) return 0;
        if(mem[i]!=-1) return mem[i];
        int ans{};
        
        
         // int ans = 0;
        // if (s.charAt(idx) == ')') {
        //     if (idx > 0 && s.charAt(idx - 1) == '(') {
        //         ans += 2; // '(' ')' at idx-1 and idx
        //         ans += dp(s, idx - 2); // previous valid length
        //     } else if (idx > 0 && s.charAt(idx - 1) == ')') {
        //         int prevLen = dp(s, idx - 1); // idx-1 has valid parentheses?
        //         if (prevLen > 0 && idx - prevLen - 1 >= 0 && s.charAt(idx- prevLen - 1) == '(') {
        //             ans += 2; // '(' pair with ')' at idx
        //             ans += prevLen; // length use s[idx -1] as end
        //             ans += dp(s, idx - prevLen - 2); // more previous length
        //         }
        //     }
        // }
        
        if(s[i]==')' )
        {
            if(i>0 and s[i-1]=='(')
            {
                ans+=2;
                ans+=dp(i-2,s);
            }
            else if(i>0 and s[i-1]==')')
            {
                int prev=dp(i-1,s);

                 if(prev>0 and i-prev-1>=0 and s[i-prev-1]=='(')
                {
                    ans+=2;
                    ans+=prev;
                    ans+=dp(i-prev-2,s);
                }
            }
        }
         mem[i]=ans;
        return ans;
        
    }
    int longestValidParentheses(string s) {
//         stack<int>st;
//         int n=s.size();
//         int ans=0;
//         for(int i=0;i<n;i++)
//         {
//             if(s[i]=='(') st.push(i);
//             else{
//                 if(!st.empty())
//                 {
//                     if(s[st.top()]=='(')
//                     {
//                         st.pop();
//                     }
//                     else
//                     {
//                         st.push(i);
//                     }
//                 }
//                 else 
//                 {
//                     st.push(i);
//                 }
//             }
//         }
//         if(st.empty())
//         {
//             ans=n;
//         }
//         else{
//             int a=n,b{};
//             while(!st.empty())
//             {
//                 b=st.top();
//                 st.pop();
//                 ans=max(ans,a-b-1);
//                 a=b;
                
//             }
//             ans=max(ans,a);

//         }
//         return ans;
        
        memset(mem,-1,sizeof(mem));
        int n=s.size();
        int ans{};
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp(i,s));
        }
        return ans;
    }
};