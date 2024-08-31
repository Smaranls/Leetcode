class Solution {

public:
    int solve(const string& s, const string& revs, int i, int j,
              vector<vector<int>>& dp) {
        if (i == s.size() || j == revs.size()) {
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;

        if (s[i] == revs[j]) {
            ans = 1 + solve(s, revs, i + 1, j + 1, dp);
        }

        else {
            ans =
                max(solve(s, revs, i + 1, j, dp), solve(s, revs, i, j + 1, dp));
        }

        return dp[i][j]=ans;
    }

    int longestPalindromeSubseq(string s) {

        // reverse then apply longest common subsequence
        string revs = s;
        reverse(revs.begin(), revs.end());
        vector<vector<int>> dp(s.size(), vector<int>(revs.size(), -1));
        return solve(s, revs, 0, 0, dp);
    }
};
