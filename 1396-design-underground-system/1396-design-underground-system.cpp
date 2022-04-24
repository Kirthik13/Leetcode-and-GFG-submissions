class UndergroundSystem {
public:
    map<pair<string,string>,vector<int>>m1;
    unordered_map<int,pair<string,int>>chkin;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        chkin[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string,int>g=chkin[id];
        m1[{g.first,stationName}].push_back(t-g.second);
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        int sum{};
        int n=m1[{startStation,endStation}].size();
        for(auto &i:m1[{startStation,endStation}])
        {
            sum+=i;
        }
        double totsum=sum*1.0;
        
        return (totsum)/(n*1.0);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */