class Solution {
public:
    // Helper function to convert a Roman numeral character to its integer value
    int char2num(char a) {
        switch (a) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0; // Handles invalid characters
        }
    }

    int romanToInt(string s) {
        int result = 0;

        // Traverse the string from left to right
        for (int i = 0; i < s.length(); i++) {
            // If the current value is less than the next, subtract it
            if (i + 1 < s.length() && char2num(s[i]) < char2num(s[i + 1])) {
                result -= char2num(s[i]);
            } else {
                // Otherwise, add it to the result
                result += char2num(s[i]);
            }
        }

        return result; // Final converted integer
    }
};
