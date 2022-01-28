class WordDictionary {
public:
    unordered_map<int,vector<string>>m;
    
    bool iseq(string &s,string &word)
    {
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='.' or word[i]=='.') continue;
            
            if(s[i]!=word[i]) return 0;
                
        }
        return 1;
    }
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        m[word.size()].push_back(word);
       
    }
    
    bool search(string word) {
       for(auto &i:m[word.size()])
       {
           if(iseq(i,word))
           {
               return 1;
           }
       }
        return 0;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */