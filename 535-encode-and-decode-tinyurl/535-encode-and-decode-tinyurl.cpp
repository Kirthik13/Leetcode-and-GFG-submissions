class Solution {
public:
    unordered_map<string,string>m;
    unordered_map<string,string>m2;

    // Encodes a URL to a shortened URL.
    int cnt=1;
    string encode(string longUrl) {
        string s=to_string(cnt);
        string s2="url"+s;
        m[longUrl]=s2;
        m2[s2]=longUrl;
        cnt++;
        return s2;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m2[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));