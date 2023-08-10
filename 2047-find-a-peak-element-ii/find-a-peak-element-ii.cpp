class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int M = mat.size();
        int N = mat[0].size();
        
        int i = 0;
        int j = 0;
        
        while (true) {
            int maxI = i;
            int maxJ = j;
            
            if (i > 0 && mat[i-1][j] > mat[maxI][maxJ]) {
                maxI = i-1;
                maxJ = j;
            }
            if (j > 0 && mat[i][j-1] > mat[maxI][maxJ]) {
                maxI = i;
                maxJ = j-1;
            }
            if (i < M-1 && mat[i+1][j] > mat[maxI][maxJ]) {
                maxI = i+1;
                maxJ = j;
            }
            if (j < N-1 && mat[i][j+1] > mat[maxI][maxJ]) {
                maxI = i;
                maxJ = j+1;
            }
            
            if (i == maxI && j == maxJ) break;
            i = maxI;
            j = maxJ;
        }
        
        return {i, j};
    }
};


// class Solution {
// public:
//     vector<int> findPeakGrid(vector<vector<int>>& mat) {
//         int n = mat.size(), m = mat[0].size();
//         for(int i = 0; i < n; i++) {
//             int low = 0, high = m - 1;
//             while(low <= high) {
//                 int mid = low + (high - low) / 2;
//                 int left = -1, right = -1, up = -1, down = -1;

//                 if(mid >= 1) left = mat[i][mid - 1];
//                 if(mid < m - 1) right = mat[i][mid + 1];
//                 if(i >= 1) up = mat[i - 1][mid];
//                 if(i < n - 1) down = mat[i + 1][mid];

//                 if((mat[i][mid] > left) && (mat[i][mid] > right) && (mat[i][mid] > up) && (mat[i][mid] > down)) return {i, mid};

//                 if(left < right) low = mid + 1;
//                 else high = mid - 1;
//             }
//         }
//         return {-1, -1};
//     }
// }; 