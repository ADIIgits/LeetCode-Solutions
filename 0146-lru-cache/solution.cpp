class LRUCache {
public:
    list<int> quelist;
    //key -> {value,iterator}
    unordered_map<int,pair<int,list<int>::iterator>> map;
    int size = 0;
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(map.count(key)){
            quelist.splice(quelist.begin(),quelist,map[key].second);
            return map[key].first;
        }
        //move getted one to front of queuelist

        else return -1;
    }
    
    void put(int key, int value) {
        if(map.count(key)){
            map[key].first = value;
            quelist.splice(quelist.begin(),quelist,map[key].second);
        } else {
            if(quelist.size() == size){
                map.erase(quelist.back());
                quelist.pop_back();
            }
            quelist.push_front(key);
            map[key] = {value,quelist.begin()};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
