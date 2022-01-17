class Solution {
public:
    bool wordPattern(string pat, string s) {
        int n1=pat.size();
s.push_back(' ');
        int n2=s.size();

int i{},j{};
string sam;
unordered_map<char,string>m;
while(i<n1 and j<n2)
{
    // cout<<m.size()<<endl;
    if(s[j]==' '){
        // cout<<"sam : "<<sam<<endl;
        if(m.find(pat[i])==m.end())
        {
            for(auto b:m)
            {
                if(b.second==sam)
                {
                    // r"false";
                    return 0;
                }
            }
        m.insert({pat[i],sam});
        }
        else{
            // deb2(s[i],sam);
            if(m[pat[i]]!=sam)
            {
                // cout<<"false";
                return 0;
            }
            
        }
        sam.clear();
        i++;

    }
    else if(isalpha(s[j]))
    {
        sam.push_back(s[j]);
    }
    j++;
    // cout<<"j : "<<j<<endl;
    //    cout<<"sam : "<<sam<<endl;

}
        // cout<<m.size();
        // for(auto b:m)
        // {
        //     cout<<b.first<<" "<<b.second<<endl;
        // }
        if(i==n1 and j==n2){
        return 1;
        }
        return 0;
    }
};