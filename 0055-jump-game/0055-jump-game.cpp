class Solution {
bool solve(int indx , vector<int> &nums,vector<int> &dp){
    if(indx ==nums.size()-1){
        return true;
    }
  
    if(dp[indx]!=-1){
        return dp[indx];
    }
    int reach =min(indx + nums[indx], (int)nums.size() - 1); 

    for(int i=indx+1;i<=reach;i++){
        if(solve(i,nums,dp)){
            return  dp[indx]=true;
        }
    }

    return dp[indx]=false;
}
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(0,nums,dp);
        

        
    }
};