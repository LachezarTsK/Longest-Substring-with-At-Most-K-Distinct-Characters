
public class Solution {

    private static final int ASCII_TABLE_SIZE = 128;

    public int lengthOfLongestSubstringKDistinct(String input, int maxDistinctCharacters) {
        int[] frequency = new int[ASCII_TABLE_SIZE];

        int left = 0;
        int right = 0;
        int maxLengthSubstring = 0;
        int numberOfDistinctCharacters = 0;

        while (right < input.length()) {

            if (++frequency[input.codePointAt(right)] == 1) {
                ++numberOfDistinctCharacters;
            }

            while (left <= right && numberOfDistinctCharacters > maxDistinctCharacters) {
                if (--frequency[input.codePointAt(left)] == 0) {
                    --numberOfDistinctCharacters;
                }
                ++left;
            }

            maxLengthSubstring = Math.max(maxLengthSubstring, right - left + 1);
            ++right;
        }
        return maxLengthSubstring;
    }
}
