class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size() - 1; // Start from the last character of the string

        // Skip any trailing spaces at the end
        while (n >= 0 && s[n] == ' ') {
            n--;
        }

        int count = 0; // To store the length of the last word

        // Count characters of the last word until a space or start of string
        while (n >= 0 && s[n] != ' ') {
            count++;
            n--;
        }

        return count; // Return the length of the last word
    }
};
