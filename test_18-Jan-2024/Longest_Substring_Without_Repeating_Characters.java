// leetcode problem no: 3
// problem name:  Longest Substring Without Repeating Characters
// problem link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

// solution: 

class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> mp = new HashMap<>();
        int lastIndex = 0;
        int maxLength = 0;

        for (int i = 0; i < s.length(); i++) {

            if (mp.containsKey(s.charAt(i))) {
                maxLength = Math.max(i - lastIndex, maxLength);
                for (int j = lastIndex; j < mp.get(s.charAt(i)); j++) {
                    mp.remove(s.charAt(j));
                }

                lastIndex = mp.get(s.charAt(i)) + 1;
                mp.put(s.charAt(i), i);
            } else {

                mp.put(s.charAt(i), i);
            }
        }
        maxLength = Math.max(s.length() - lastIndex, maxLength);

        return maxLength;

    }
}