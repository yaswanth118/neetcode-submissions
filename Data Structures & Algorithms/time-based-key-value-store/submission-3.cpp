class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[{key, timestamp}] = value;
    }
    
    string get(string key, int timestamp) {
        auto itr = mp.lower_bound({key,timestamp});
        if(itr == mp.end()) return "";
        if(itr->first.first != key) {
            return "";
        }
        return itr == mp.end()?"":itr->second;
    }
private:
map<pair<string,int>, string , greater<pair<string,int>>> mp;

};
