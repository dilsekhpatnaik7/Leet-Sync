class Solution {
public:
    void getCombinations(int index, int n, int k, vector<int>& ds, vector<vector<int>>& ans) {
        if(index == n + 1) {
            if(ds.size() == k) {
                ans.push_back(ds);
            }
            return;
        }

        ds.push_back(index);
        getCombinations(index + 1, n, k, ds, ans);
        ds.pop_back();
        getCombinations(index + 1, n, k, ds, ans);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> ds;
        vector<vector<int>> ans;

        getCombinations(1, n, k, ds, ans);
        return ans;
    }
};