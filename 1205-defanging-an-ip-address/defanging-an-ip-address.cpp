class Solution {
public:
    string defangIPaddr(string address) {
        string ans = "";
        for(auto i: address) {
            if(i == '.') {
                ans += '[';
                ans += '.';
                ans += ']';
            } else {
                ans += i;
            }
        }
        return ans;
    }
};