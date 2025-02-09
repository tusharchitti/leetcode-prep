class Solution {
    public:
        vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
            unordered_map<int, int> mpp;
            for (int j = 0; j < elements.size();j++) {
                if (mpp.find(elements[j]) ==mpp.end())
                    mpp[elements[j]] = j;
                else
                    mpp[elements[j]] = min(mpp[elements[j]],j);
            }
            
            vector<int> res;
            res.reserve(groups.size());
            for (int k : groups) {
                int mini = INT_MAX;
                for (int i = 1; i*i <= k;i++) {
                    if (k%i == 0) {
                        if (mpp.find(i) != mpp.end())
                            mini = min(mini,mpp[i]);
                        int temp = k/i;
                        if (temp != i && mpp.find(temp) !=mpp.end())
                            mini = min(mini,mpp[temp]);
                    }
                }
                res.push_back(mini == INT_MAX ?-1 : mini);
            }
            return res;
        }
    };
    