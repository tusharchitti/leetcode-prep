class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start;
        vector<int> end;
        int flowerSize = flowers.size();
        for(int i=0;i<flowers.size();i++)
        {
            start.push_back(flowers[i][0]);
            end.push_back(flowers[i][1]+1);
        }
        sort(start.begin(),start.end());
        sort(end.begin(), end.end());
        vector<int> ans;
        for(int i=0;i<people.size();i++)
        {
            int started = 0;
            int ended = 0;
            auto it = std::lower_bound(start.begin(), start.end(), people[i]+1);
            if(it == start.end())
            {
                 started = flowerSize;
            }
            else
            {
                int distance = std::distance(start.begin(), it);
                started = distance ;
            }

            auto it1 = std::lower_bound(end.begin(), end.end(), people[i]+1);
            if(it1 == end.end())
            {
                 ended = flowerSize;
            }
            else
            {
                int distance = std::distance(end.begin(), it1);
                ended = distance ;
            }
            ans.push_back(started-ended);
        }
        return ans;
    }
};