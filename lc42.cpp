class Solution {
public:
    int trap(vector<int>& height) {
        
        int ans = 0;               // Total water trapped
        int n = height.size();     // Size of the height array

        int left = 0;              // Left pointer
        int right = n - 1;         // Right pointer

        int leftmax = 0;           // Maximum height to the left of current position
        int rightmax = 0;          // Maximum height to the right of current position

        // Loop until the two pointers meet
        while (left < right) {

            // If the height at left is less than height at right,
            // we process the left side
            if (height[left] < height[right]) {

                // If current height is greater than or equal to leftmax,
                // update leftmax
                if (height[left] >= leftmax) {
                    leftmax = height[left];
                }
                // Otherwise, water can be trapped
                else {
                    ans += leftmax - height[left];
                }

                left++; // Move the left pointer to the right
            }

            // Else process the right side
            else {

                // If current height is greater than or equal to rightmax,
                // update rightmax
                if (height[right] >= rightmax) {
                    rightmax = height[right];
                }
                // Otherwise, water can be trapped
                else {
                    ans += rightmax - height[right];
                }

                right--; // Move the right pointer to the left
            }
        }

        return ans; // Return the total trapped water
    }
};
