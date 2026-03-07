class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result; // This will store all unique triplets that sum to 0

        // Step 1: Sort the array to make it easier to avoid duplicates and use two-pointer technique
        sort(nums.begin(), nums.end());

        // Step 2: Loop through each number as a potential first element of the triplet
        for (int i = 0; i < nums.size(); i++) {

            // Skip duplicate values for the first element to avoid repeating triplets
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Initialize two pointers for the current 'i'
            int left = i + 1;                 // start just after 'i'
            int right = nums.size() - 1;      // start at the end of the array

            // Step 3: Use two-pointer technique to find pairs that sum with nums[i] to 0
            while (left < right) {
                int total = nums[i] + nums[left] + nums[right]; // calculate the sum of the triplet

                if (total == 0) {
                    // Found a valid triplet
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate values for 'right' pointer
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    // Skip duplicate values for 'left' pointer
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }

                    // Move both pointers inward to look for the next possible triplet
                    left++;
                    right--;
                }
                else if (total > 0) {
                    // If the sum is too large, decrease it by moving 'right' leftward
                    right--;
                }
                else {
                    // If the sum is too small, increase it by moving 'left' rightward
                    left++;
                }
            }
        }
        // Step 4: Return the list of unique triplets
        return result;
    }
};
