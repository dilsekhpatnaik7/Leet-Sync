class Solution {
public:
    void generateAllBinaryStrings(int index, int num, string str, vector<string>& res) {
        if(index == num) {
            res.push_back(str);
            return;
        }
        generateAllBinaryStrings(index + 1, num, str + '0', res);
        generateAllBinaryStrings(index + 1, num, str + '1', res);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string, int> map;
        for(auto i: nums) {
            map[i]++;
        }

        int num = nums[0].size();
        vector<string> res;
        generateAllBinaryStrings(0, num, "", res);
        for(auto i: res) {
            if(map.find(i) == map.end()) return i;
        }
        return "";
    }
};