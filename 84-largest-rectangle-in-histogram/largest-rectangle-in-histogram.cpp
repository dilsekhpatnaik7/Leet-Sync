class Solution {
public:
    void leftSmaller(int n, vector<int>& heights, vector<int>& leftSmall, stack<int>& st) {
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();

            if(st.empty()) leftSmall[i] = 0;
            else leftSmall[i] = st.top() + 1;
            st.push(i);
        }
    }

    void rightSmaller(int n, vector<int>& heights, vector<int>& rightSmall, stack<int>& st) {
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();

            if(st.empty()) rightSmall[i] = n - 1;
            else rightSmall[i] = st.top() - 1;
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> leftSmall(n), rightSmall(n);
        leftSmaller(n, heights, leftSmall, st);
        while(!st.empty()) st.pop();
        rightSmaller(n, heights, rightSmall, st);

        int maximum = 0;
        for(int i = 0; i < n; i++) {
            maximum = max(maximum, heights[i] * (rightSmall[i] - leftSmall[i] + 1));
        }
        return maximum;
    }
};