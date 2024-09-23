class Solution {

int solve (int amount, vector<int>& coins, vector<vector<int>> &dp,int indx ){
    if(amount==0){
        return 1;
    }
    if(amount<0 || indx>=coins.size()){
        return 0;

    }

    if(dp[indx][amount]!=-1){
        return dp[indx][amount];
    }

    int inc = solve(amount -coins[indx],coins,dp,indx);
    int exc =solve(amount,coins,dp,indx+1);


    return dp[indx][amount]=inc+exc;


}
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        int ans = solve(amount,coins,dp,0);

        return ans;
    }
};