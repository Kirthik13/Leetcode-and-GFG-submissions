class Encrypter {
public:
    map<char,string>m1;
    // map<string,vector<char>>m2;
    unordered_map<string,int>dic;

//     void fn(string &s2,string sam,int i,int &ans,unordered_set<string>&vis)
//     {
//         if(i>=s2.size())
//         {
//             if(dic.find(sam)!=dic.end()) 
//             {
//                 if(vis.find(sam)==vis.end())
//                 {
//                     // cout<<"sam : "<<sam<<endl;
//                     ++ans;
//                     vis.insert(sam);
//                 }
//             }
//             return;
//         }
    
//             string dum=s2.substr(i,2);
//             // fn(dum);
// //             for(int j=0;j<m2[dum].size();j++)
// //             {
                
// //             }
//         for(auto j:m2[dum])
//         {
//             sam.push_back(j);
//             fn(s2,sam,i+2,ans,vis);
//             sam.pop_back();
//         }
        
//     }
    
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i=0;i<keys.size();i++)
        {
            m1[keys[i]]=values[i];
            // m2[values[i]].push_back(keys[i]);
        }
        
        for(auto &i:dictionary)
        {
            string sam=encrypt(i);
            // int f=1;
            // for(auto &j:i){
            //     // dic.insert(i);
            //     if(m1.count(j)==0)
            //     {
            //         f=0;
            //         break;
            //     }
            //     sam+=(m1[j]);
            // }
            // if(f){
            dic[sam]++;
            // }
            // cout<<"Sam : "<<sam<<endl;
        }
    }
    
    string encrypt(string s1) {
        string ans;
        for(auto &i:s1)
        {
            if(m1.count(i)==0){
                return "";
            }
            ans+=(m1[i]);
        }
        return ans;
    }
    
    
    int decrypt(string s2) {
        // int ans{};
        // unordered_set<string>vis;
        //  fn(s2,"",0,ans,vis);
        // return ans;
        // cout<<"s2 : "<<s2<<endl;
        return dic[s2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */