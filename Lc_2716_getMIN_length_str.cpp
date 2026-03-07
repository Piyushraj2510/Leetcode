#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizedStringLength(string s) {
        stack<char> st;
        sort(s.begin(), s.end());

        for (char ch : s) {
            if (!st.empty() && st.top() == ch) {
                continue;
            } else {
                st.push(ch);
            }
        }

        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result.length();
    }
};


#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Minimized String Length
    --------------------------------
    Given a string 's' consisting of lowercase English letters, 
    remove duplicate characters so that each character appears only once.
    Return the length of the resulting minimized string.

    Approach:
    ---------
    1. Sort the string to bring identical characters together.
    2. Use a stack to store characters while removing duplicates:
        - If the stack top is the same as current character, skip it.
        - Otherwise, push the character onto the stack.
    3. After processing, the stack contains all unique characters.
    4. Return the size of the stack (length of minimized string).

    Example:
    --------
    Input: s = "abac"
    Sorted: "aabc"
    Stack processing: ['a', 'b', 'c']
    Output: 3
*/
/*
class Solution {
public:
    int minimizedStringLength(string s) {
        stack<char> st;                   // Stack to store unique characters
        sort(s.begin(), s.end());         // Step 1: Sort the string

        // Step 2: Traverse the string
        for (char ch : s) {
            if (!st.empty() && st.top() == ch) {
                continue;                 // Skip duplicate characters
            } else {
                st.push(ch);              // Push unique character
            }
        }

        // Step 3: Build the resulting string from the stack
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());  // Step 4: Reverse to restore order

        return result.length();                 // Step 5: Return length
    }
};
*/