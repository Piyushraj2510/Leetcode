class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        // If the input list is empty, return empty string
        if (strs.empty()) {
            return "";
        }

        // Assume the first string is the initial common prefix
        string prefix = strs[0];

        // Compare the prefix with each string in the list
        for (int i = 1; i < strs.size(); i++) {

            // While the current string does not start with the prefix
            while (strs[i].find(prefix) != 0) {
                // Shorten the prefix by removing the last character
                prefix = prefix.substr(0, prefix.size() - 1);

                // If prefix becomes empty, no common prefix exists
                if (prefix.empty()) {
                    return "";
                }
            }
        }

        // Return the longest common prefix
        return prefix;
    }
};
