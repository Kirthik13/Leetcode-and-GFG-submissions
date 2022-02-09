class Solution {
public:
    bool isSumEqual(string f, string s, string t) {
        string fn,sn;
        for(auto &i:f)
        {
            fn+=char(i-'a'+48);
        }
  for(auto &i:s)
        {
            sn+=char(i-'a'+48);
        }
        string tn;
          for(auto &i:t)
        {
            tn+=char(i-'a'+48);
        }
        // cout<<fn<<" "<<sn<<" " <<tn<<endl;
        // cout<<to_string(stoi(fn)+stoi(sn))<<endl;
        return stoi(tn)==(stoi(fn)+stoi(sn));
        
    }
};