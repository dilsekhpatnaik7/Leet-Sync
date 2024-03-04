class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size(), left = 0, right = n - 1;
        int score = 0;
        int maximumScore = 0;

        while (left <= right) {
            if (power >= tokens[left]) {
                power -= tokens[left];
                score += 1;
                left += 1;
                maximumScore = max(maximumScore, score);
            } else if (score > 0) {
                power += tokens[right];
                score -= 1;
                right -= 1;
            } else {
                break;
            }
        }
        return maximumScore;
    }
};