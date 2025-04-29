class Comparator
{
public:
    bool operator()(const vector<int>& first, const vector<int>& second)
    {
        // Compare based on the time (first[0] is the time)
        return first[0] > second[0]; // Min-heap, so we return true if first[0] > second[0]
    }
};

class Solution {
public:
    bool validate(int i, int j, int n) {
        return i >= 0 && j >= 0 && i < n && j < n;
    }

    vector<vector<int>> getAdj(int i, int j, int n) {
        vector<vector<int>> adj;
        // Check four directions (up, down, left, right)
        if (validate(i+1, j, n)) adj.push_back({i+1, j});
        if (validate(i-1, j, n)) adj.push_back({i-1, j});
        if (validate(i, j+1, n)) adj.push_back({i, j+1});
        if (validate(i, j-1, n)) adj.push_back({i, j-1});
        return adj;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        // Priority queue stores {time, row, col}
        priority_queue<vector<int>, vector<vector<int>>, Comparator> pq;
        pq.push({grid[0][0], 0, 0}); // Start at (0, 0) with the initial time being grid[0][0]
        
        vector<vector<bool>> visit(n, vector<bool>(n, false)); // Visited cells
        visit[0][0] = true;

        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            int time = curr[0], x = curr[1], y = curr[2];

            // If we've reached the bottom-right corner
            if (x == n-1 && y == n-1) {
                return time; // Return the time it takes to reach (n-1, n-1)
            }

            // Check all adjacent cells
            vector<vector<int>> neighbors = getAdj(x, y, n);
            for (const auto& neighbor : neighbors) {
                int nx = neighbor[0], ny = neighbor[1];
                // If the neighbor is within bounds and not visited
                if (!visit[nx][ny]) {
                    // The time to reach this cell is max(current time, elevation at the neighbor)
                    pq.push({max(time, grid[nx][ny]), nx, ny});
                    visit[nx][ny] = true; // Mark the cell as visited after adding to the queue
                }
            }
        }

        return -1; // In case there's no valid path (shouldn't happen in this problem)
    }
};
