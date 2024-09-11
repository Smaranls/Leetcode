class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;
        int maxarea = 0;
        while (left < right) {

            int currheight = min(height[right], height[left]);
            int currwidth = right - left;
            int currarea = currheight * currwidth;
           maxarea = max(maxarea, currarea);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxarea;
    }
};