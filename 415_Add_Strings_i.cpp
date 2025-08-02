class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1;
        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            int n1 = (i >= 0) ? num1[i--] - '0' : 0;
            int n2 = (j >= 0) ? num2[j--] - '0' : 0;

            int sum = n1 + n2 + carry;
            carry = sum / 10;
            result += (sum % 10 + '0');
        }

        reverse(result.begin(), result.end());
        return result;
    }
};