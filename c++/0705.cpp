// Link: https://leetcode.com/problems/design-hashset/
// Runtime: 260 ms 
// Memory: 39.4 MB

class MyHashSet 
{
public:
    MyHashSet()
    {
        
    }
    
    void add(int key)
    {
        if (std::find(set.begin(), set.end(), key) == set.end()) set.push_back(key);    
    }
    
    void remove(int key)
    {
        auto it = std::find(set.begin(), set.end(), key);
        if (it != set.end()) set.erase(it);
    }
    
    bool contains(int key) 
    {
        if (std::find(set.begin(), set.end(), key) == set.end()) return false;
        else return true;
    }
private:
    std::vector<int>set;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
