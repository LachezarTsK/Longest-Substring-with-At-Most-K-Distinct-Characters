
function lengthOfLongestSubstringKDistinct(input: string, maxDistinctCharacters: number): number {
    const ASCII_TABLE_SIZE = 128;
    const frequency = new Array<number>(ASCII_TABLE_SIZE).fill(0);

    let left = 0;
    let right = 0;
    let maxLengthSubstring = 0;
    let numberOfDistinctCharacters = 0;

    while (right < input.length) {

        if (++frequency[input.codePointAt(right)] === 1) {
            ++numberOfDistinctCharacters;
        }

        while (left <= right && numberOfDistinctCharacters > maxDistinctCharacters) {
            if (--frequency[input.codePointAt(left)] === 0) {
                --numberOfDistinctCharacters;
            }
            ++left;
        }

        maxLengthSubstring = Math.max(maxLengthSubstring, right - left + 1);
        ++right;
    }
    return maxLengthSubstring;
};
