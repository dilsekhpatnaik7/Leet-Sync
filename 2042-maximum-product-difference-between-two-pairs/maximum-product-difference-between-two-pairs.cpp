class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int m=nums[nums.size()-1] * nums[nums.size()-2];
        int n=nums[0] * nums[1];
        return m-n;
    }
};