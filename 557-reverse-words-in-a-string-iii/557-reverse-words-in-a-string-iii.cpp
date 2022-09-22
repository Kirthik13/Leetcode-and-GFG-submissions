class Solution {
public:
    string reverseWords(string s) {
        stringstream st(s);
        string temp;
        vector<string>cont;
        while(st>>temp)
        {
            // cout<<temp<<endl;
            std::reverse(begin(temp),end(temp));
            cont.push_back(temp);
        }
        
        string totans;
        int idx{};
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ' )
            {
                if(s[i-1]!=' ')
                {
                    totans+=cont[idx++];
                    totans.push_back(' ');
                }
                else{
                    totans.push_back(' ');

                }
            }
        }
        totans+=cont[idx++];
        return totans;
    }
};