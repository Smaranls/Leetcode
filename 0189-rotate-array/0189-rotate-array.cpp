class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size =nums.size();
        vector<int> ans(size);
        for (int i =0 ;i<size ;i++){
            ans[(i+k)%size]=nums[i];

        }
        nums =ans ;
        
    }
};