class Solution { 
public:
    int lengthOfLongestSubstring(string s) {
        string window = "";      // Stores current substring without repeating characters
        int maxlen = 0;          // Tracks the maximum length of valid substring found

        // Loop through each character in the string
        for (int i = 0; i < s.length(); i++) {
            // Find if current character already exists in the current window
            int pos = window.find(s[i]);

            // If character is found (i.e., repeated)
            if (pos != -1) {
                // Remove all characters up to and including the repeated one
                // substr(pos + 1) creates a substring starting after the repeated character
                window = window.substr(pos + 1);
            }

            // Add the current character to the window
            window += s[i];

            // Update the max length if the current window is longer
            if (maxlen < window.length()) {
                maxlen = window.length();
            }
        }

        // Return the maximum length of substring without repeating characters
        return maxlen;
    }
};
