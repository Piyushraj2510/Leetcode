class Solution {
public:
    int strStr(string haystack, string needle) {
        // Check if needle exists in haystack using built-in function
        if (haystack.find(needle) != string::npos) {
            
            // If both strings are of equal length and needle exists, return 0
            if (haystack.size() == needle.size()) {
                return 0;
            }

            int n = needle.size(); // Length of the needle
            int low = 0;           // Start index for comparison

            // Loop while the remaining part of haystack is long enough to contain needle
            while (low + n - 1 < haystack.size()) {
                // Compare the substring of haystack with needle
                if (haystack.substr(low, n) == needle) {
                    return low;  // Match found at index 'low'
                } else {
                    low++;  // Move window forward
                }
            }
        }

        // If needle is not found, return -1
        return -1;
    }
};
