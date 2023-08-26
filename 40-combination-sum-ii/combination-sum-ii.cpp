class Solution {
public:
    void getUniqueCombinations(int index, vector<int>& candidates, int target, vector<int>& ds, vector<vector<int>>& ans) {
        if(index == candidates.size()) {
            if(target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        if(candidates[index] <= target) {
            ds.push_back(candidates[index]);
            getUniqueCombinations(index + 1, candidates, target - candidates[index], ds, ans);
            ds.pop_back();
        }

        while(index + 1 < candidates.size() && candidates[index + 1] == candidates[index]) index++;

        getUniqueCombinations(index + 1, candidates, target, ds, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;

        getUniqueCombinations(0, candidates, target, ds, ans);
        return ans;
    }
};