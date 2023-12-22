class Solution {
public:
    bool isBoundary(int row, int col, int n, int m, vector<vector<char>>& maze) {
        return (row == 0 || row == n - 1 || col == 0 || col == m - 1) && maze[row][col] != '+';
    }

    bool isValid(int nrow, int ncol, int n, int m, vector<vector<char>>& maze) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && maze[nrow][ncol] == '.';
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[entrance[0]][entrance[1]] = 0;
        maze[entrance[0]][entrance[1]] = '+';

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        q.push({0, {entrance[0], entrance[1]}});

        while(!q.empty()) {
            int distance = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();

            if(isBoundary(row, col, n, m, maze)) return distance;
            for(int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                
                if(isValid(nrow, ncol, n, m, maze)) {
                    if(distance + 1 < dist[nrow][ncol]) {
                        dist[nrow][ncol] = distance + 1;
                        q.push({distance + 1, {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
    }
};