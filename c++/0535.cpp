// Link: https://leetcode.com/problems/encode-and-decode-tinyurl/
// Runtime: 9 ms
// Memory: 7.2 MB

class Solution {
public:
  // Encodes a URL to a shortened URL.
  string encode(const string &longUrl) {
    srand(time(nullptr));
    std::string code = getCode(longUrl, 0);
    while (hashmap.find("http://tinyurl.com/" + code) != hashmap.end())
      code = getCode(longUrl, rand());
    hashmap[code] = longUrl;
    return code;
  }

  // Decodes a shortened URL to its original URL.
  string decode(const string &shortUrl) { return hashmap[shortUrl]; }

private:
  const int kHash = 1000007;
  std::unordered_map<std::string, std::string> hashmap;

  std::string getCode(const std::string &url, int offset) {
    unsigned long long code = offset;
    for (char s : url)
      code = (code * 11 + s) % kHash;
    return std::to_string(code);
  }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));