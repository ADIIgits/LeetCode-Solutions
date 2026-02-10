class LRUCache {
    int capacity;
    list<int> quelist;
    unordered_map<int,pair<int,list<int>::iterator>> map;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(map.find(key)!=map.end()){
            quelist.splice(quelist.begin(),quelist,map[key].second);
            return map[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        //map stores {key,{value,iterator}}
        //list stores key
        if(map.find(key)!=map.end()){
            map[key].first = value;
            quelist.splice(quelist.begin(),quelist,map[key].second);
            return;
        }
        if(quelist.size()==capacity){
            map.erase(quelist.back());
            quelist.pop_back();
        }
        quelist.push_front(key);
        map[key] = {value,quelist.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */