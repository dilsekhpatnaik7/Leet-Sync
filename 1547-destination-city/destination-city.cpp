class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> m;
        for(auto i: paths) {
            m[i[0]]++;
        }

        for(auto i: paths) {
            string t = i[1];
            if(m.find(t) == m.end()) return t;
        }
        return "";
    }
};