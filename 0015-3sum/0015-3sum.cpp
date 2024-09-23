class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        vector<vector<int>> solve;
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            };

            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    solve.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }

                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                }

                else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return solve;
    }
};