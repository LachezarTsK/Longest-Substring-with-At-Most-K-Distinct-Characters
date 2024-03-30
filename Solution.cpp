
#include <array>
#include <string>
#include <algorithm>
using namespace std;

class Solution {

    static const int ASCII_TABLE_SIZE = 128;

public:
    int lengthOfLongestSubstringKDistinct(const string& input, int maxDistinctCharacters) const {
        array<int, ASCII_TABLE_SIZE>  frequency{};

        int left = 0;
        int right = 0;
        int maxLengthSubstring = 0;
        int numberOfDistinctCharacters = 0;

        while (right < input.length()) {

            if (++frequency[input[right]] == 1) {
                ++numberOfDistinctCharacters;
            }

            while (left <= right && numberOfDistinctCharacters > maxDistinctCharacters) {
                if (--frequency[input[left]] == 0) {
                    --numberOfDistinctCharacters;
                }
                ++left;
            }

            maxLengthSubstring = max(maxLengthSubstring, right - left + 1);
            ++right;
        }
        return maxLengthSubstring;
    }
};
