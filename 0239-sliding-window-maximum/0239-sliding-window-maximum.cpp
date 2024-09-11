class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;
        deque<int> dq;
        int n = nums.size();

        for(int i=0;i<n;i++){
            //[5,2,3] i=4 new element pop 5 
            if(!dq.empty() && dq.front() ==i-k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};