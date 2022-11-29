class RandomizedSet {
public:
    map<int,int>m;
    vector<int>v;
    int siz{};
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val)!=m.end()) return 0;
        
        m[val]=siz;
        v.push_back(val);
        siz++;
        return 1;
    }
    
    bool remove(int val) {
         if(m.find(val)==m.end()) return 0;
        int lastel=v.back();
        int lastidx=m[lastel];
        int repidx=m[val];
        swap(v[lastidx],v[m[val]]);
        v.pop_back();
        m[lastel]=repidx;
        m.erase(val);
        siz--;
        return 1;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */