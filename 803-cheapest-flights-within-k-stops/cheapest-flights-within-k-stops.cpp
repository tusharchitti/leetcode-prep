#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build adjacency list
        vector<vector<pair<int, int>>> graph(n);
        for (auto& flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        // Min-heap: (cost, node, stops)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});

        // visited[node][stops] = min cost to reach node with 'stops' stops
        vector<vector<int>> visited(n, vector<int>(k + 2, INT_MAX));
        visited[src][0] = 0;

        while (!pq.empty()) {
            vector<int> top = pq.top(); pq.pop();
            int cost = top[0];
            int u = top[1];
            int stops = top[2];

            if (u == dst) return cost;

            if (stops > k) continue;

            for (auto& [v, price] : graph[u]) {
                int newCost = cost + price;

                if (newCost < visited[v][stops + 1]) {
                    visited[v][stops + 1] = newCost;
                    pq.push({newCost, v, stops + 1});
                }
            }
        }

        return -1;
    }
};
