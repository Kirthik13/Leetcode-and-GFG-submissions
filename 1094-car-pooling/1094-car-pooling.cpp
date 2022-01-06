class Solution {
public:
    bool carPooling(vector<vector<int>>& v, int cap) {
     
   
    vector<pair<int,int>>tp;

    for(auto i:v)
    {
      tp.push_back({i[1],i[0]});
      tp.push_back({i[2],-i[0]});
    }
    sort(begin(tp),end(tp));

    int filled{};

    for(auto i:tp)
    {
        filled+=i.second;
        if(filled>cap)
        {
            // cout<<"false"<<endl;
         
    
                return 0;
                // cout<<"false";
                // f=1;
                // break;
        }
            }
        

    
    
    return 1;
    }
};