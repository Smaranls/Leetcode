class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int high =0;
        int low =0;
        int mini =INT_MAX;
        int n = nums.size();
        int total=0;

        while(high<n){
            total+=nums[high];
            high++;

            while(total>=target){
                total-=nums[low];
                low++;
                int wndow = high-low;
                mini =min(wndow+1,mini);
            }
        }
        if(mini==INT_MAX){
            return 0;
        }
        return mini;
    }
};