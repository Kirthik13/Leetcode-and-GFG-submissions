class Solution {
public:
    bool checkInclusion(string s1, string s2) {
//         int hash{};
//         for(auto &i:s1)
//         {
//             hash+=(int(i)-'a'+1);
//         }
        
//         int currhash{};
//         for(int i=0;i<s1.size();i++)
//         {
//             currhash+=(int(s2[i])-'a'+1);
//         }
        
//         if(currhash==hash) return 1;
//                     cout<<currhash<<" "<<hash<<endl;
// cout<<endl;
//         for(int i=s1.size();i<s2.size();i++)
//         {
//             currhash-=int(s2[i-s1.size()]-'a'+1);
//             currhash+=(int(s2[i])-'a'+1);
//             cout<<currhash<<" "<<hash<<endl;
//             if(currhash==hash) return 1;

//         }
        
//         return 0;
        
        if(s1.size()>s2.size()) return 0;
        map<char,int>m1,m2;
        
        for(auto &i:s1) m1[i]++;
        
        for(int i=0;i<s1.size();i++)
        {
            m2[s2[i]]++;    
        }
        
        if(m1==m2) return 1;
        
        // for(auto &i:m1) cout<<i.first<<" "<<i.second<<endl;
        // cout<<endl;
                // for(auto &i:m2) cout<<i.first<<" "<<i.second<<endl;

        for(int i=s1.size();i<s2.size();i++)
        {
            m2[s2[i-s1.size()]]--;
            if(m2.find(s2[i-s1.size()])!=m2.end() and m2[s2[i-s1.size()]]==0) 
            {
                m2.erase(s2[i-s1.size()]);
            }
            m2[s2[i]]++;
            
                            // for(auto &i:m2) cout<<i.first<<" "<<i.second<<endl;

            if(m2==m1) return 1;

        }
        
        return 0;
    }
    
};