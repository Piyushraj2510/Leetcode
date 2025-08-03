class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;  // Stores last index of each character
        int start = 0;                       // Start index of current window
        int maxLen = 0;                      // Maximum length of non-repeating substring

        for (int end = 0; end < s.length(); end++) {
            char currentChar = s[end];

            // If character is already in map and its last position is inside the current windowunordered_map.count(key) returns:

            //1 if the key exists in the map.

            //0 if it does not exist.
            if (charIndex.count(currentChar) > 0 && charIndex[currentChar] >= start) {
                // Move start to just after the previous occurrence
                start = charIndex[currentChar] + 1;
            }

            // Update the current character's last seen index
            charIndex[currentChar] = end;

            // Calculate the current window length and update max length
            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};