class Solution {
public:
    // Recursive helper function using memoization
    int solve(vector<int>& coins, int amount, vector<int>& dp) {
        // Base case: If the amount is zero, no coins are needed
        if (amount == 0) return 0;
        
        // If the amount is negative, return an impossible value (infinity)
        if (amount < 0) return INT_MAX;

        // If we've already computed the result for this amount, return it
        if (dp[amount] != -1) return dp[amount];

        int mini = INT_MAX;

        // Try every coin
        for (int coin : coins) {
            int res = solve(coins, amount - coin, dp); // Recurse for the remaining amount
            if (res != INT_MAX) { // Only update if it's not an impossible case
                mini = min(mini, res + 1); // Add one to the result since we're using one coin
            }
        }

        // Store the result in the memoization table
        dp[amount] = mini;
        return mini;
    }

    // Main function to solve the coin change problem
    int coinChange(vector<int>& coins, int amount) {
        // Create a memoization table and initialize with -1 (uncomputed)
        vector<int> dp(amount + 1, -1);

        // Get the result using the recursive helper function
        int result = solve(coins, amount, dp);

        // If result is still infinity, return -1 to indicate no solution
        return result == INT_MAX ? -1 : result;
    }
};
