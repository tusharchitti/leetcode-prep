class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
             if(nums[i] == 10) {
                ans = ans - 10;
             }else if (nums[i]/10 == 0) {
                ans = ans + nums[i];       
             }else{
                ans = ans - nums[i];
             }
        }
        if (ans == 0) return false;
        return true;
    }
};