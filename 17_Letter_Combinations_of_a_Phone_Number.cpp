class Solution {
private:
    // Recursive helper function to build combinations
    void solve(string digits, string output, string mapping[], int index, vector<string>& ans)
    {
        // Base case: when index reaches the end of the digits string
        if (index >= digits.length())
        {
            ans.push_back(output); // Add the complete combination to result
            return;
        }

        // Convert current digit character to an integer
        int number = digits[index] - '0';
        // Get corresponding letters for the current digit from the mapping
        string value = mapping[number];

        // Loop over each character mapped to the current digit
        for (int i = 0; i < value.length(); i++)
        {
            // Choose one character from the mapped string
            output.push_back(value[i]);      // Append to current combination
            solve(digits, output, mapping, index + 1, ans);  // Move to the next digit
            output.pop_back();               // Backtrack to try next character
        }
    }

public:
    // Main function to be called with the input digit string
    vector<string> letterCombinations(string digits) {
        vector<string> ans;  // To store all combinations

        // Edge case: if input is empty, return empty list
        if (digits.length() == 0) {
            return ans;
        }

        // Mapping of digits to corresponding letters (just like a phone keypad)
        string mapping[10] = {
            "",     // 0 has no letters
            "",     // 1 has no letters
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        int index = 0;         // Start from the first digit
        string output = "";    // Temporary string to build combinations

        // Begin recursion
        solve(digits, output, mapping, index, ans);
        return ans;
    }
};
