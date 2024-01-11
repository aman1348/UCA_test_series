// leetcode problem no: 11
// problem name: Container With Most Water
// problem link: https://leetcode.com/problems/container-with-most-water/description/

// solution: 


class Solution {
    
    public int maxArea(int[] height) {
        int maxArea = 0;
        int area = 0;
        for(int i = 0, j = height.length-1; i<j; ) {
            area = Math.min(height[i], height[j]) * (j - i);
            maxArea = Math.max(maxArea, area);

            if(height[i] < height[j]) i++;
            else j--;
        }
        return maxArea;
    }
}