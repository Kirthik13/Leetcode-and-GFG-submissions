class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& v) {
        vector<pair<int,int>>stp;
        int m=v.size(),n=v[0].size();
        int i=m-1,j=0;
        while(i>=0)
        {
            stp.push_back({i,j});
            i--;
        }
        i=0;
        while(j<n)
        {
            if(i==0 and j==0)
            {
                j++;
                continue;
            }
            stp.push_back({i,j});
            j++;
        }
        j=0;
        
        
        for(int i=0;i<stp.size();i++)
        {
            int cr=stp[i].first;
            int cc=stp[i].second;
            int tcr=stp[i].first;
            int tcc=stp[i].second;
            
            // cout<<cr<<" "<<cc<<endl<<endl;
            vector<int>currmat;
            int lcr,lcc;
            while(cr<m and cc<n)
            {
                  lcr=cr;
                lcc=cc;
                currmat.push_back(v[cr][cc]);
              
                
                cr++;
                cc++;
                
            }
            sort(begin(currmat),end(currmat));
            
//             for(auto &k:currmat) cout<<k<<" ";
//             cout<<endl;
            
          
            // cout<<lcr<<" "<<lcc<<endl;
            int idx=currmat.size()-1;
            while(lcr>=tcr and lcc>=tcc)
            {
                
                v[lcr][lcc]=currmat[idx];
                lcr--;
                lcc--;
                idx--;
                
            }
            
            
        }
        
        return v;
        
                
        
    }
};