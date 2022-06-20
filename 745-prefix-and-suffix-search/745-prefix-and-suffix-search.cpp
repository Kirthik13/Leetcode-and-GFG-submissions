class WordFilter {
public:
    unordered_map<string,int>m;
    WordFilter(vector<string>& v) {
        for(int i=0;i<v.size();i++)
        {
            int n=v[i].size();
            string s=v[i];
            for(int j=1;j<=n;j++)
            {
                string t=s.substr(0,j);
                for(int k=0;k<n;k++)
                {
                    string h=s.substr(k);
                    // cout<<"t : "<<t<<" =>  h : "<<h<<endl;

                    m[t+"|"+h]=i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string t=prefix+"|"+suffix;
        if(m.find(t)==m.end()) return -1;
        return m[t];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */