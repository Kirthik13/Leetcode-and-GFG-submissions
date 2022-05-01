class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1,s2;
        
        for(auto &i:s)
        {
            if(isalpha(i)) s1.push(i);
            else
            {
                if(!s1.empty()) s1.pop();
            }
        }
        for(auto &i:t)
        {
            if(isalpha(i)) s2.push(i);
            else
            {
                if(!s2.empty()) s2.pop();
            }
        }
        // while(!s1.empty())
        // {
        //     cout<<s1.top()<<" ";
        //     s1.pop();
        // }
        // cout<<endl;
        //  while(!s2.empty())
        // {
        //     cout<<s2.top()<<" ";
        //     s2.pop();
        // }
        // cout<<"next : "<<endl;
        if(s1==s2) return 1;
        return 0;
    }
};