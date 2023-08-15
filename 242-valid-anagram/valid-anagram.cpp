class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char, int> count;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            count[s[i]]++;
            count[t[i]]--;
        }
        for(int i = 0; i < n; i++) {
            if(count[s[i]] != 0) return false;
        }
        return true;
    }
};