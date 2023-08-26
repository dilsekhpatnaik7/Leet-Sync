class Solution {
public:
    void getSubsets(int index, vector<int>& arr, vector<int>& ds, set<vector<int>>& res) {
        if(index == arr.size()) {
            res.insert(ds);
            return;
        }

        ds.push_back(arr[index]);
        getSubsets(index + 1, arr, ds, res);

        ds.pop_back();
        getSubsets(index + 1, arr, ds, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ds;
        set<vector<int>> res;

        getSubsets(0, nums, ds, res);
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};