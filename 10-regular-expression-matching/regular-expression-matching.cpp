class Solution {
public:
    bool findreg(vector<vector<int>>&dp,string s, string p , int si, int pi)
    {
        if(dp[si][pi]!=-1) return dp[si][pi];
        if(pi==p.length() && si == s.length())
        {
            dp[si][pi] =1;
            return true;
        } 
        else if(pi == p.length())
        {
            dp[si][pi] =0;
            return false;
        }
    
        bool found = false;

        if(si<s.length() && (p[pi] == s[si] || p[pi] =='.'))
        {
            found = true;
        }

        if(pi+1<p.length() && p[pi+1] == '*')
        {
            bool ret = findreg(dp,s,p,si,pi+2) || (found && findreg(dp,s,p,si+1,pi));
            dp[si][pi] = ret;
            return ret;
        }

        if(found)
        {
            bool ret = findreg(dp,s,p,si+1,pi+1);
            dp[si][pi] = ret;
            return ret;
        }
        dp[si][pi] = 0;
        return false;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length()+1, vector<int>(p.length()+1,-1));
        findreg(dp,s,p,0,0);
        return dp[0][0];
    }
};