class Solution {
public:

    int split(vector<int>& nums , int currIndex, int k,vector<vector<int>>&dp)
    {
        if(currIndex  == nums.size() && k !=0)
        {
            return INT_MAX;
        }
        
        if(k==0)
        {
            return INT_MAX;
        }

        if(dp[currIndex][k] != -1)
        {
            return dp[currIndex][k];
        }

        if(k == 1)
        {
            int sum = 0;
            for(int i=currIndex;i<nums.size();i++)
            {
                sum = sum+ nums[i];
            }
            dp[currIndex][k] =sum;
            return sum;
        }

        int sum = 0;
        int ans = INT_MAX;
        for(int i=currIndex;i<nums.size();i++)
        {
            sum = sum+nums[i];
            int tmpsum = split(nums, i+1 ,k-1,dp);
            ans = min(ans, max(sum,tmpsum));
        }
        dp[currIndex][k] =ans;
        return ans;
    }
    int splitArray(vector<int>& nums, int k) {
        int len = nums.size();
        vector<vector<int>> dp(len+1, vector<int>(k+1, -1));
        return split(nums, 0, k, dp);
    }
};