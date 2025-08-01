class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;                      // Pointer starting from the left
        int n = nums.size();              // Total number of elements
        int right = n - 1;                // Pointer starting from the right

        vector<int> ans(n);               // Result vector of size n
        n--;                              // 'n' will be used as index to fill result from end

        // Special case: if only one element, square it directly
        if (n == 0) {  
            ans[0] = nums[0] * nums[0]; 
            return ans;
        }

        // Loop until the two pointers meet
        while (left <= right) {
            int leftSq = nums[left] * nums[left];
            int rightSq = nums[right] * nums[right];

            // Place the larger square at the current highest index (n), and move pointers
            if (leftSq > rightSq) {
                ans[n] = leftSq;
                left++;
            } else {
                ans[n] = rightSq;
                right--;
            }
            n--;  // Move index to the next position (from end to start)
        }

        return ans;  // Return the sorted squares array
    }
};
