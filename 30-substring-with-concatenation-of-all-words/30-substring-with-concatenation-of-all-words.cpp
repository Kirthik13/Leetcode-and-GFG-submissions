class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& v) {
        int n=v.size();
        int wordsiz=v[0].size();
        int win=n*wordsiz;
        
        unordered_map<string,int>m,temp;
        
        vector<int>ans;
        int strsize=s.size();
        for(auto &i:v) m[i]++;
        
        for(int i=0;i<=strsize-win;i++)
        {
            for(int j=i;j<i+win;j+=wordsiz)
            {
                string sam=s.substr(j,wordsiz);
                
                if(m.find(sam)!=m.end())
                {
                    temp[sam]++;
                }
                else{
                    break;
                }
                
            }
            
            if(temp==m) ans.push_back(i);
            
            temp.clear();
        }
            return ans;

    }
};
