class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> ballmp;
        vector<int>ansArr;
        unordered_map<int, int> mp;
        int ans =0;
        for(int i=0;i<queries.size();i++) {
            if(ballmp.find(queries[i][0]) != ballmp.end())
            {
                mp[ballmp[queries[i][0]]] -- ;
                if(mp[ballmp[queries[i][0]]] == 0) {
                        ans--;
                }
            }
            mp[queries[i][1]]++;
            if(mp[queries[i][1]] == 1) {
                ans++;
            }
            ballmp[queries[i][0]] = queries[i][1];
            ansArr.push_back(ans); 
        }
        return ansArr;
    }
};