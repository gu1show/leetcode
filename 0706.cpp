class MyHashMap {
public:
    MyHashMap()
    {
            
    }
    
    void put(int key, int value) 
    {
        int i = 0;
        bool isFound = false;
        
        if (canFind(i, isFound, key)) hashmap[i - 1].second = value;
        else hashmap.push_back(std::make_pair(key, value));
    }
    
    int get(int key) 
    {
        int i = 0;
        bool isFound = false;
        
        if (canFind(i, isFound, key)) return hashmap[i - 1].second;
        else return -1;
    }
    
    void remove(int key) 
    {
        int i = 0;
        bool isFound = false;

        if (canFind(i, isFound, key)) hashmap.erase(hashmap.begin() + i - 1);
    }
    
private:
    std::vector<std::pair<int, int>> hashmap;
    
    bool canFind(int& i, bool& isFound, int key)
    {
        while ((i < hashmap.size()) && (!isFound))
        {
            if (hashmap[i].first == key) isFound = true;
            i++;
        }
        
        return isFound;
    }        
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */