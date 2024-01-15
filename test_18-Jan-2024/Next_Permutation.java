// leetcode problem no: 31
// leetcode probmen name: Next Permutation
// problem link: https: https://leetcode.com/problems/next-permutation/description/

// solution: 

class Solution {
    public void nextPermutation(int[] nums) {
        int i = nums.length-1;
        while(i>0 && nums[i-1]>=nums[i]) i--;
        if(i>0)
        {
            int num = i;
            for(int j = i+1; j<nums.length; j++)
            {
                if(nums[j]>nums[i-1] && nums[j]<nums[num])
                {
                    num = j;
                }
            }
            int temp = nums[num];
            nums[num] = nums[i-1];
            nums[i-1] = temp;
        }
        Arrays.sort(nums,i,nums.length);
    }
}
