class ParkingSystem {
public:
    int big{},med{},small{};
    
    ParkingSystem(int big1, int medium1, int small1) {
        this->big=big1;
        this->med=medium1;
        this->small=small1;
        
    }
    
    bool addCar(int car) {
        if(car==1)
        {
            if(big==0) return 0;
            big--;
            return 1;
        }
        if(car==2)
        {
            if(med==0) return 0;
            med--;
            return 1;
        }
        
            if(small==0) return 0;
            small--;
            return 1;
        
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */