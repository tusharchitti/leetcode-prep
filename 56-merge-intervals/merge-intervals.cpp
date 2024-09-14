class Solution {
public:

/**

case1 : done
[1,3]  [5,6] =. [1,3] [5,6]


case2 :
[1,6]  [2,3] => [1,6]

case3 :
[1 ,4/6] [4,8] =>  [1,8]

for(;;){
    []
}

**/
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        if(a[0]==b[0])
        return a[1] < b[1];
        return a[0] < b[0]; // Compare the first element of each row
    });
     vector<vector<int>> ans;
     int count  = 0;
     int size = intervals.size();
     for(int i=0;i<size;i++){
        if(ans.size() == 0 ) {
            ans.push_back({intervals[i][0],intervals[i][1]});
            count++;
        }
        else {
            vector<int> merged = ans[count-1];
            if(intervals[i][0]>merged[1]){
                ans.push_back({intervals[i][0],intervals[i][1]});
                count++;
            }
            if(intervals[i][1] >= merged[1]) {
                ans[count-1][1] = intervals[i][1] ;
            }
        }
     }
     return ans;
    }
};