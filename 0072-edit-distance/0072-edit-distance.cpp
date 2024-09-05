class Solution {
private:
    int solve(string word1 , string word2 ,int i,int j,vector<vector<int>> &dp){
        int a=word1.length();
        int b = word2.length();

        if(a==i){
            return b -j;
        }

        if(b==j){
            return a-i;
        }

        int ans =0;

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if (word1[i] == word2[j]){
            return solve(word1,word2,i+1,j+1,dp);
        }

        
    
        {
           int  include= 1 + solve(word1,word2,i,j+1,dp) ;
           int exclude= 1 + solve(word1,word2,i+1,j,dp);
           int replace = 1+ solve(word1,word2,i+1,j+1,dp); 
            ans =min(include,min(exclude,replace));
        }   

        dp[i][j]=ans ;
        return dp[i][j];

    }
public:
    int minDistance(string word1, string word2) {
        int a=word1.length();
        int b = word2.length();
        vector<vector<int>> dp(a,vector<int>(b,-1)) ;
        int ans = solve(word1,word2, 0,0,dp);
        return ans;
    }
};