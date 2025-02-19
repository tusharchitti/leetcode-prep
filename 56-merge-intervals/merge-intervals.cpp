class Solution {
public:
    vector<int> MergeOverlappingInterval(vector<int> first, vector<int> second)
    {
          // case 1 [2, 4] [5,6] => no change-done
          // case 2  [2,4] [2 8] => merge them done
          // case 3   [2,5] [3,5] =>  merge them
          // case 4   [2,5] [3,4] => merge them
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
           if(MergeOverlappingInterval(recentMergedVector, intervals[i]).size() == 0)
           {
            mergedVector.push_back(intervals[i]);
           }
           else
           {
            mergedVector.pop_back();
            mergedVector.push_back(MergeOverlappingInterval(recentMergedVector, intervals[i]));
           }
        }
        return mergedVector;
    }
};