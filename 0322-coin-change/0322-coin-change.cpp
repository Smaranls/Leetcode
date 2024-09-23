class Solution {
int solve(vector<int>& coins, int amount,vector<int> &dp){
    if(amount==0){
        return 0;
    }

    if(amount<0){
        return INT_MAX;
    }

    if(dp[amount]!=-1){
        return dp[amount];
    }
    int mini =INT_MAX;

    for(int coin:coins){
        int res = solve(coins,amount-coin,dp);
        if(res!=INT_MAX){
            mini=min(mini,res+1);
        }
    }
    dp[amount]=mini;
    return dp[amount];
}
public:
    int coinChange(vector<int>& coins, int amount) {
        //create a dp 
        vector<int> dp(amount+1,-1);

        int res =solve(coins,amount,dp);
        return res == INT_MAX ? -1 : res;
    }
};