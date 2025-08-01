class Solution {
public:
    int romanToInt(string s) {
        // Mapping of Roman symbols to their integer values
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int result = 0;
        int n = s.size();

        // Traverse each character in the string
        for (int i = 0; i < n; i++) {
            int val = roman[s[i]]; // Current Roman numeral value
            int nextval = 0;

            // Look ahead to the next value (if within bounds)
            if (i + 1 < n) {
                nextval = roman[s[i + 1]];
            }

            // If current value is less than next value, subtract (e.g., IV = 4)
            if (val < nextval) {
                result -= val;
            } else {
                // Otherwise, just add it
                result += val;
            }
        }

        return result; // Final integer result
    }
};
