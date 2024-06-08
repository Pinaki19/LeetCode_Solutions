class LRUCache {
private:
    int timestamp,capacity;
    unordered_map<int,pair<int,int>> mapping;
    function<bool (int,int)> comp=[&mapping=mapping](int k1,int k2)->bool{
        return mapping[k1].second<mapping[k2].second;
    };
    set<int,decltype(comp)> s;
public:
    LRUCache(int capacity):capacity(capacity),timestamp(1),s(comp) {
        ios_base::sync_with_stdio(0);
    } 
    
    int get(int key) {
        if(mapping.find(key)==mapping.end())
            return -1;
        int val=mapping[key].first;
        s.erase(key);
        mapping[key]={val,timestamp++};
        s.insert(key);
        return val;
    }
    
    void put(int key, int value) {
        if(s.find(key)==s.end()){
            if(capacity==0){
                int oldest=*s.begin();
                s.erase(s.begin());
                mapping.erase(oldest);
            }else
                 capacity--;
        }
        else
            s.erase(key);
        mapping[key]={value,timestamp++};
        s.insert(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */