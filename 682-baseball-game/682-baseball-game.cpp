class Solution {
public:
    int calPoints(vector<string>& v) {
        int score{};
        vector<int>v2;
        for(int i=0;i<v.size();i++)
        {
            string sam=v[i];
            // const char *p= sam.c_str();
            if(!isalpha(sam[0]) and v[i]!="+")
            {
                // score+=stoi(v[i]);
                int g=stoi(sam);
                // cout<<"sam[0] : "<<sam[0]<<endl;
                v2.push_back(g);
            }
            else if(v[i]=="+")
            {
                // cout<<v2.back()<<endl;
                // cout<<v2[v2.size()-2]<<endl;
                v2.push_back(v2.back()+v2[v2.size()-2]);
            }
            else if(v[i]=="C")
            {
                v2.pop_back();
            }
            else if(v[i]=="D"){
                int b=v2.back();
                // v2.pop_back();
                v2.push_back(b*2);
            }
            // for(auto &j:v2)
            // {
            //     cout<<j<<" ";
            // }
            // cout<<endl;
        }
        return accumulate(begin(v2),end(v2),0);
    }
};