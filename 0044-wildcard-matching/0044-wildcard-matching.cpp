// class Solution {
// private:
//     bool solve(string s, string p, int i, int j, vector<vector<int>>& dp) {
//         if (i < 0 && j < 0) {
//             return true;
//         }

//         if (j < 0) {
//             return false;
//         }
//         if (i < 0) {
//             for (int k = 0; k <= j; k++) {
//                 if (p[k] != '*') {
//                     return false;
//                 }
//             }
//             return true;
//         }

//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }
//         // match

//         if (p[j] == '?' || p[j] == s[i]) {
//             return dp[i][j] = solve(s, p, i - 1, j - 1, dp);
//         }
//         if (p[j] == '*') {
//             return dp[i][j] = (solve(s, p, i - 1, j, dp) ||
//                                (solve(s, p, i, j - 1, dp)));
//         }

//         return dp[i][j] = false;
//     }

// public:
//     bool isMatch(string s, string p) {
//         int l1 = s.size();
//         int l2 = p.size();

//         vector<vector<int>> dp(l1, vector<int>(l2, -1));

//         return solve(s, p, l1 - 1, l2 - 1, dp);
//     }
// };

class Solution {
private:
    bool solve(string &s, string &p, int i, int j, vector<vector<int>> &dp) {
        // Base cases
        if (i < 0 && j < 0) return true;      // Both strings are exhausted
        if (j < 0) return false;              // Pattern is exhausted but string is not
        if (i < 0) {                          // String is exhausted but pattern remains
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') return false; // Can only match if remaining pattern is all '*'
            }
            return true;
        }
        
        // If the result is already computed, return it
        if (dp[i][j] != -1) return dp[i][j];
        
        // If characters match or there's a '?', move both indices
        if (p[j] == s[i] || p[j] == '?') {
            return dp[i][j] = solve(s, p, i - 1, j - 1, dp);
        }
        
        // If there's a '*', it can match zero or more characters
        if (p[j] == '*') {
            return dp[i][j] = (solve(s, p, i - 1, j, dp) || solve(s, p, i, j - 1, dp));
        }
        
        // Otherwise, the characters don't match
        return dp[i][j] = false;
    }
    
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        // Initialize dp table with -1 (not yet computed)
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // Start recursion from the last characters of both strings
        return solve(s, p, m - 1, n - 1, dp);
    }
};