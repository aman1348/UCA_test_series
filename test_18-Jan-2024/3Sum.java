// leetcode problem no: 15
// problem name: 3Sum
// problem link: https://leetcode.com/problems/3sum/description/

// solution: 

class Solution {

    private List<Integer> createTriplet(int a, int b, int c) {
        List<Integer> triplet = new ArrayList<>();
        triplet.add(a);
        triplet.add(b);
        triplet.add(c);
        return triplet;
    }

    private void validPairSum(int[] nums, int start, int k, List<List<Integer>> result) {
        HashMap<Integer, Boolean> map = new HashMap<>();
        for(int i = start; i<nums.length; i++) {
            if(map.getOrDefault(nums[i], false)) continue;
            if(map.containsKey(nums[i])) {
                result.add(createTriplet(-1 * k,k - nums[i] , nums[i]));
                map.put(nums[i], true);
            }
            else {
                map.put(k - nums[i], false);
            }
        }
    }
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        int n = nums.length;
        Arrays.sort(nums);
        for(int i = 0; i<=n - 3; i++) {
            if(i!=0 && nums[i] == nums[i-1]) continue;
            validPairSum(nums, i + 1, -1 * nums[i], result);
        }
        return result;
    }
}