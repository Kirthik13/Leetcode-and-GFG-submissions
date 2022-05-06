class Solution {
public:
    string removeDuplicates(string s, int k) {
     string ans;
//         stack<pair<int,char>>st;
//         for(auto i:s)
//         {
//             if(st.empty())
//             {
//                 st.push({1,i});
//             }
//             else{
//                 if(st.top().second==i)
//                 {
//                     st.top().first++;
//                     if(st.top().first==k) 
//                     {
//                         st.pop();
//                     }
//                 }
//                 else{
//                     st.push({1,i});

//                 }
                
//             }
//         }
//         while(!st.empty())
//         {
//             char ch=st.top().second;
//             int nos=st.top().first;
//                ans.append(p.first, p.second);
//             st.pop();
//         }
        vector<int>cnt(s.size());
        int i{},j{};
        while(j<s.size())
        {
            s[i]=s[j];
            cnt[i]=(i>0 and s[i-1]==s[j])?cnt[i-1]+1:1;
            if(cnt[i]==k) i-=k;
            i++;
            j++;
        }
        return s.substr(0,i);
    }
};