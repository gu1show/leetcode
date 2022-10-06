// Link: https://leetcode.com/problems/time-based-key-value-store/
// Runtime: 728 ms
// Memory: 130.8 MB

class TimeMap
{
public:
    TimeMap()
    {
        
    }
    
    void set(const std::string& key, const std::string& value, int timestamp) 
    {
        timeMap[key][timestamp] = value; 
    }
    
    std::string get(const std::string& key, int timestamp)
    {
        if (timeMap.find(key) != timeMap.end())
        {
            auto it = timeMap[key].upper_bound(timestamp);
            if (it == timeMap[key].begin()) return "";
            else return prev(it)->second;
        }
        else return "";
    }
    
private:
    std::unordered_map<std::string, std::map<int, std::string>> timeMap;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
