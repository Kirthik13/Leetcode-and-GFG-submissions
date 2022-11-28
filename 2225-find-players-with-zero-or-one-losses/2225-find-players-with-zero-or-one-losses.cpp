class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& v) {
         // vector<vector<int>>tot(2);
        
        // map<int,int>m;    
        // set<int>st;
        
//         for(auto &i:v)
//         {
            
//             st.insert(i[0]);
//             st.insert(i[1]);
            
//             m[i[1]]++;
            
//         }
        
        
//         for(auto &i:st)
//         {
//             if(m[i]==1)
//             {
//                 tot[1].push_back(i);
//             }
//             else 
//             {
//                 if(m[i]==0){
//                 tot[0].push_back(i);
//                 }
//             }            
            
//         }
        // return tot;
        
          vector<vector<int>>ans(2);
        
       map<int,int>m;
        for(auto i:v)
        {
            if(m[i[0]]>=0){
            m[i[0]]++;
            }
            // if(m.count(i[1])!=0){
                if(m[i[1]]<=0){
            m[i[1]]--;
                }
            // else if(m[i[1]]>0)
            else
            {
                m[i[1]]=-1;
            }
            // }
            
        }
//         for(auto i:m)
//         {
//             cout<<i.first<<" "<<i.second<<endl;
//         }
        
        for(auto &i:m)
        {
            if(i.second>0)
            {
                ans[0].push_back(i.first);
            }
            else if(i.second==-1){
                ans[1].push_back(i.first);
            }
        }
        return ans;
        
        
    }
};