
using System;

public class Solution
{
    private static readonly int ASCII_TABLE_SIZE = 128;

    public int LengthOfLongestSubstringKDistinct(String input, int maxDistinctCharacters)
    {
        int[] frequency = new int[ASCII_TABLE_SIZE];

        int left = 0;
        int right = 0;
        int maxLengthSubstring = 0;
        int numberOfDistinctCharacters = 0;

        while (right < input.Length)
        {

            if (++frequency[input[right]] == 1)
            {
                ++numberOfDistinctCharacters;
            }

            while (left <= right && numberOfDistinctCharacters > maxDistinctCharacters)
            {
                if (--frequency[input[left]] == 0)
                {
                    --numberOfDistinctCharacters;
                }
                ++left;
            }

            maxLengthSubstring = Math.Max(maxLengthSubstring, right - left + 1);
            ++right;
        }
        return maxLengthSubstring;
    }
}
