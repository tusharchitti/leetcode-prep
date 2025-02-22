class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pqMinEffort;
        vector<vector<int>> minValue(n, vector<int>(m, INT_MAX));
        pqMinEffort.push({0, 0, 0});
        
        vector<int> directions = {0, 1, 0, -1, 0};

        while (!pqMinEffort.empty()) {
            vector<int> top = pqMinEffort.top();
            pqMinEffort.pop();

            if (top[0] == n-1 && top[1] == m-1) return top[2];  // ✅ Early exit
            
            if (top[2] > minValue[top[0]][top[1]]) continue;  // ✅ Skip worse paths
            
            for (int d = 0; d < 4; d++) {
                int nx = top[0] + directions[d];
                int ny = top[1] + directions[d + 1];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int diffFromTop = abs(heights[top[0]][top[1]] - heights[nx][ny]);
                    int newEffort = max(top[2], diffFromTop);

                    if (newEffort < minValue[nx][ny]) {
                        minValue[nx][ny] = newEffort;
                        pqMinEffort.push({nx, ny, newEffort});
                    }
                }
            }
        }

        return -1;  // Should never reach here
    }
};
