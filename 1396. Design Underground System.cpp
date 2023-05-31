class UndergroundSystem {
public:
 map<int,pair<string,int>>st;
 map<string,pair<int,int>>end;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
       st[id]=make_pair(stationName,t);

    }
    
    void checkOut(int id, string stationName, int t) {
       
        string str=st[id].first+'-'+stationName;
        end[str].first+=t-st[id].second;
        end[str].second+=1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string res=startStation+'-'+endStation;
        double num=end[res].first;
        double den=end[res].second;
        double ans=num/den;
        return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */