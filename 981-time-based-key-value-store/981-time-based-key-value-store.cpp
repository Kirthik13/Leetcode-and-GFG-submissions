class TimeMap {
public:
    map<pair<string,int>,string>m;
    map<string,string>chk;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[{key,timestamp}]=value;
        chk[key]=value;
    }
    
    string get(string key, int timestamp) {
        if(m.find({key,timestamp})!=m.end()) return  m[{key,timestamp}];
        if(chk.find(key)==chk.end()) return "";
        
        int g=timestamp;
        while(g--)
        {
                   if(m.find({key,g})!=m.end()) return  m[{key,g}];
 
        }
        
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */