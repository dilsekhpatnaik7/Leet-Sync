class Solution {
public:
    void getUniquePermutations(int index, vector<int>& nums,  set<vector<int>>& res) {
        if(index == nums.size()) {
            res.insert(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            getUniquePermutations(index + 1, nums, res);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        getUniquePermutations(0, nums, res);

        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};