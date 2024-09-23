class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> sol;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];

            if (sol.find(diff) != sol.end()) {
                ans.push_back (sol[diff]); 
                ans.push_back(i);
                return ans;
            }
            sol[nums[i]] = i;
        }

        return ans;
    }
};