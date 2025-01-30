class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> data;
        
        // Convert buildings into events
        for (auto& building : buildings) {
            data.emplace_back(building[0], building[2]);  // Start event
            data.emplace_back(building[1], -building[2]); // End event
        }

        // **Sort events correctly**
        sort(data.begin(), data.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) 
                return a.first < b.first;  // Sort by x-coordinate
            
            return a.second > b.second; // If same x, taller heights first (start event), smaller heights first (end event)
        });

        multiset<int> currentHeight = {0}; // Track active heights
        vector<vector<int>> ans;
        int prevMaxHeight = 0;

        for (auto& event : data) {
            int x = event.first, h = event.second;

            if (h > 0) {
                // **Start of a building**
                currentHeight.insert(h);
            } else {
                // **End of a building**
                currentHeight.erase(currentHeight.find(-h)); 
            }

            int maxHeight = *currentHeight.rbegin(); // Get max height
            
            if (maxHeight != prevMaxHeight) { 
                // Only add key point if height actually changes
                ans.push_back({x, maxHeight});
                prevMaxHeight = maxHeight;
            }
        }
        return ans;
    }
};