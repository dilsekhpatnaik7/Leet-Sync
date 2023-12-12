class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maximum = INT_MIN, secondMaximum = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= maximum) {
                secondMaximum = maximum;
                maximum = nums[i];
            } else if(nums[i] > secondMaximum) {
                secondMaximum = nums[i];
            }
        }
        return (int)(maximum - 1) * (secondMaximum - 1);
    }
};