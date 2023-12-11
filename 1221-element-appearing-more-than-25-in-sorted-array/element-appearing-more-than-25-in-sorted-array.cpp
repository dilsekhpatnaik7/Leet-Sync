class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int requiredSize = n / 4;
        int count = 1;

        int currentElement = arr[0];
        for(int i = 1; i < n; i++) {
            if(currentElement == arr[i]) count++;
            else count = 1;

            if(count > requiredSize) return arr[i];
            currentElement = arr[i];
        }
        return currentElement;
    }
};