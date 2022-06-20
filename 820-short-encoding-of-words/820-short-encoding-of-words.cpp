
    bool compare(string &a,string &b){
    return a.length()>b.length();
}
class Solution {
public:
    int minimumLengthEncoding(vector<string>& v) {
        sort(begin(v),end(v),compare);
        
        string res=v[0]+"#";
        
        for(int i=1;i<v.size();i++)
        {
            string t=v[i]+"#";
            auto it=res.find(t);
            if(it==-1)
            {
                res+=(t);
            }
        }
        return res.size();
    }
};