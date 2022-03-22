class Solution {
public:
    string getSmallestString(int n, int k) {
//          string res;
// int m=k;

// for(int i=0;i<n;i++){
//     res+='a';
//     m--;
// }
// int idx=res.size()-1;
// while(m>=26)
// {
//     res[idx--]='z';
//     m=m-25;

// }


// res[idx]=char(m+'a');
//         return res;
     string s;
        for(int i=0;i<n;i++)
        {
            s+='a';
            k--;
        }
        int idx=s.size()-1;
        // cout<<s<<endl;
        while(k>=26 )
        {
            s[idx]='z';
            k=k-25;
            idx--;
            // cout<<s<<endl;
            // cout<<k<<endl;
        }
        
        s[idx]=char(k+'a');
        
        return s;
    }
};