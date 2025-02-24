class Solution {
public:
    vector<int> MergeOverlappingInterval(vector<int> first, vector<int> second)
    {
          if(second[0] <= first[1])
          {
            return {first[0],max(first[1],second[1])};
          }
          return {};
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedVector;
        sort(intervals.begin(),intervals.end());
        mergedVector.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
           vector<int> recentMergedVector = mergedVector.back();
           vector<int> mergeVector =  MergeOverlappingInterval(recentMergedVector, intervals[i]);
           if(mergeVector.size() == 0)
           {
            mergedVector.push_back(intervals[i]);
           }
           else
           {
            mergedVector.pop_back();
            mergedVector.push_back(mergeVector);
           }
        }
        return mergedVector;
    }
};