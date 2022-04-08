class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words[0].size()>s.size()) return {};
        
        int win=words[0].size()*words.size();
        unordered_map<string,int>m1;
        for(auto &i:words)
        {
            m1[i]++;
        }
        vector<int>v;
        // cout<<"win : "<<win<<endl;
        for(int i=0;i<s.size();i++)
        {
            if(i>=win-1)
            {
                unordered_map<string, int>temp_map=m1;
                bool bugFound=false;
                string sam=s.substr(i-(win-1),win);
                // cout<<"sam : "<<sam<<endl;
                int currwin=words[0].size();
                // cout<<"currwin : "<<currwin<<endl;
                for(int j=i-(win-1);j<=i;j+=currwin)
                {
                    // cout<<i-(win-1)<<endl;
                     string temp=s.substr(j,currwin);
                
                if(m1.find(temp)==m1.end() || temp_map[temp]<=0) {
                    bugFound=true;
                    break;
                } else {
                    temp_map[temp]--;
                } 
                }
                
                if(!bugFound)
                {
                    v.emplace_back(i-(win-1));
                    temp_map.clear();
                }
            }
        }
        return v;
        
//          int wordLen=words.size();
//         int eachWordLen=words[0].size();
//         int window=wordLen*eachWordLen;
//         string temp="";
        
//         if(window>s.size()) {
//             return {};
//         }
        
//         unordered_map<string, int>word_count;
//         vector<int>result;
//         for(int i=0; i<wordLen; i++) {
//             word_count[words[i]]++;
//         }
        
//         for(int i=0; i<s.size()-window+1; i++) {
//             unordered_map<string, int>temp_map=word_count;
//             bool bugFound=false;
            
//             for(int j=i; j<i+window; j=j+eachWordLen) {
//                 temp=s.substr(j,eachWordLen);
//                 cout<<"temp : "<<temp<<endl;
//                 if(word_count.find(temp)==word_count.end() || temp_map[temp]<=0) {
//                     bugFound=true;
//                     break;
//                 } else {
//                     temp_map[temp]--;
//                 } 
//             }
            
//             if(!bugFound) {
//                 result.push_back(i);
//                 temp_map.clear();
//             }
//         }
//         return result;
    }
};