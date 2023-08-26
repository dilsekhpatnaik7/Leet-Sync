class Solution {
public:
    void getPermutations(int index, vector<int>& nums, vector<vector<int>>&  ans) {
        if(index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            getPermutations(index + 1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPermutations(0, nums, ans);
        return ans;
    }
};