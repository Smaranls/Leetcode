class Solution {
    bool solve(int indx, vector<int>& nums, vector<int>& dp) {
        if (indx == nums.size() - 1) { // Base case: if we reach the last index
            return true;
        }

        if (dp[indx] != -1) { // If the result is already computed
            return dp[indx];
        }

        int maxJump = min(indx + nums[indx], (int)nums.size() - 1); // The farthest we can jump

        // Try every position we can jump to
        for (int next = indx + 1; next <= maxJump; ++next) {
            if (solve(next, nums, dp)) {
                return dp[indx] = true; // If we can reach the end, store the result and return true
            }
        }

        return dp[indx] = false; // If no jump leads to the last index, store false
    }

public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1); // Initialize memoization array with -1 (unvisited)
        return solve(0, nums, dp); // Start from index 0
    }
};
