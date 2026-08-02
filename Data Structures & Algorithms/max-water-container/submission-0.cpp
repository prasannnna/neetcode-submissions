class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, n = heights.size();
        int right = n - 1, max_area = 0;
        while(left < right) {
            int h = min(heights[left], heights[right]);
            int w = right - left;
            max_area = max(h * w, max_area);
            if(heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};
