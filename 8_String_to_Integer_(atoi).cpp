class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;

        // Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // If only spaces, return 0
        if (i == n)
            return 0;

        // Determine the sign
        int sign = 1;
        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        long int result = 0;

        // Process numeric characters
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            i++;

            // Check for overflow (before applying sign)
            if (sign == -1 && -result < INT_MIN)
                return INT_MIN;
            if (sign == 1 && result > INT_MAX)
                return INT_MAX;
        }

        return sign * result; // Apply sign and return
    }
};
