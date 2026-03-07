class Solution {
private:
    // Helper function to check if all strings share the same prefix of given length
    bool iscommon(vector<string>& strs, int len) {
        string prefix = strs[0].substr(0, len);  // Extract prefix from first string
        for (int i = 1; i < strs.size(); i++) {
            // If any string does not start with the prefix, return false
            if (strs[i].find(prefix) != 0) {
                return false;
            }
        }
        return true;
    }

public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        // Step 1: Find the minimum length among all strings
        int minlen = strs[0].size();
        for (int i = 1; i < strs.size(); i++) {
            minlen = min(minlen, (int)strs[i].length());
        }

        // Step 2: Apply binary search on the prefix length
        int low = 0;
        int high = minlen;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (iscommon(strs, mid)) {
                // If prefix of length mid is common, try a longer one
                low = mid + 1;
            } else {
                // Else try a shorter prefix
                high = mid - 1;
            }
        }

        // Step 3: Return the longest common prefix found
        return strs[0].substr(0, (low + high) / 2);  // ✅ Fix: corrected formula
    }
};
