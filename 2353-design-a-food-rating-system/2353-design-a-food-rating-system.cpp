struct cmp{
    bool operator()
        (pair<int,string>a,pair<int,string>b) const{
        if(a.first==b.first) return a.second>b.second;
        return a.first<b.first;
    }
};
class FoodRatings {
public:
    map<string,string>fmap;
    map<string,int>rmap;
    map<string,set<pair<int,string>,cmp>>m2;
    
    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        for(int i=0;i<f.size();i++)
        {
            fmap[f[i]]=c[i];
            rmap[f[i]]=r[i];
            
            m2[c[i]].insert({r[i],f[i]});
            
        }
    }
    
    void changeRating(string food, int newr) {
        string c=fmap[food];
        pair<int,string>p={rmap[food],food};
        auto it=m2[c].find(p);
        m2[c].erase(it);
        m2[c].insert({newr,food});
        
        rmap[food]=newr;
        
    }
    
    string highestRated(string c) {
        auto it=m2[c].rbegin();
        return it->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */