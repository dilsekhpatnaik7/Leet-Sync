class Solution {
public:
    string getPermutation(int n, int k) {
        int factorial = 1;
        vector<int> nums;
        for(int i = 1; i < n; i++) {
            factorial *= i;
            nums.push_back(i);
        }
        nums.push_back(n);
        string ans = "";
        k = k - 1;

        while(true) {
            ans = ans + to_string(nums[k / factorial]);
            nums.erase(nums.begin() + (k / factorial));
            if(nums.size() == 0) break;
            k = k % factorial;
            factorial = factorial / nums.size();
        }
        return ans;
    }
};