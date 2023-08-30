class Solution {
public:
    void generateAllBinaryStrings(int index, int num, string str, string& ans, unordered_map<string, int>& map) {
        if(index == num) {
            if(map.find(str) == map.end()) {
                ans = str;
            }
            return;
        }
        generateAllBinaryStrings(index + 1, num, str + '0', ans, map);
        generateAllBinaryStrings(index + 1, num, str + '1', ans, map);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string, int> map;
        for(auto i: nums) {
            map[i]++;
        }

        int num = nums[0].size();
        string ans = "";
        generateAllBinaryStrings(0, num, "", ans, map);
        return ans;
    }
};