class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;             // To store squared elements
        int n = nums.size();         // Get the size of the input array

        // Step 1: Square each element and store in ans
        for (int i = 0; i < n; i++) {
            int element = nums[i] * nums[i]; // Square of current element
            ans.push_back(element);          // Add to result vector
        }

        // Step 2: Sort the squared elements
        sort(ans.begin(), ans.end());

        // Step 3: Return the sorted result
        return ans;
    }
};
