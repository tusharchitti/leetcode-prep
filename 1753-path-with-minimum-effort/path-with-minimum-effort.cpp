#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        
        // Min heap: {effort, row, col}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        
        vector<vector<int>> minEffort(n, vector<int>(m, INT_MAX));
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        pq.emplace(0, 0, 0);
        minEffort[0][0] = 0;
        
        while (!pq.empty()) {
            auto [effort, x, y] = pq.top();
            pq.pop();
            
            if (x == n - 1 && y == m - 1) return effort;  // Reached destination
            
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int newEffort = max(effort, abs(heights[x][y] - heights[nx][ny]));
                    if (newEffort < minEffort[nx][ny]) {
                        minEffort[nx][ny] = newEffort;
                        pq.emplace(newEffort, nx, ny);
                    }
                }
            }
        }
        
        return -1;  // Should never reach here
    }
};
