class Solution {
public:
    bool checkBounds( int i , int j , vector<vector<int>> &matrix)
    {
        return !(i>=matrix.size() || i<0 || j>=matrix[0].size() || j<0);
    }
    int  getValue(vector<vector<int>>& matrix , 
    vector<vector<int>>& dp , int i , int j)
    {
        if(!checkBounds(i,j,matrix))
        {
           return -1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 1;
        if(checkBounds(i+1,j, matrix)  && (matrix[i+1][j] > matrix[i][j]))
        {
           ans = max(ans, getValue(matrix, dp ,i+1,j)+1);
        }
        if(checkBounds(i-1,j, matrix)  && (matrix[i-1][j] > matrix[i][j]))
        {
           ans = max(ans, getValue(matrix, dp ,i-1,j)+1);
        }
        if(checkBounds(i,j+1, matrix) && (matrix[i][j+1] > matrix[i][j]))
        {
           ans = max(ans, getValue(matrix, dp, i,j+1)+1);
        }
        if(checkBounds(i,j-1, matrix)  && (matrix[i][j-1] > matrix[i][j]))
        {
           ans = max(ans, getValue(matrix, dp ,i,j-1)+1);
        }
        dp[i][j] = ans;
        return ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int len = matrix.size();
        int wid = matrix[0].size();
        int ans = 1;
        vector<vector<int>> dp(len, vector<int>(wid,-1));
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<wid;j++)
            {
                if(dp[i][j] == -1)
                {
                  ans = max(ans, getValue(matrix,dp,i,j));
                }
            }
        }

        return ans;
    }
};