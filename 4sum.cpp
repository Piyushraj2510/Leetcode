class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;

        // Step 1: sort the array so duplicates are adjacent and two-pointers can work
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Step 2: pick the first number
        for (int i = 0; i < n; i++) {
            // Skip duplicate values for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Step 3: pick the second number
            for (int j = i + 1; j < n; j++) {
                // Skip duplicate values for the second number
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1;          // pointer just after j
                int right = n - 1;         // pointer at the end

                // Step 4: use two pointers to find two other numbers
                while (left < right) {
                    // Use long long to avoid overflow when adding four ints
                    long long total = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (total == target) {
                        // Found a quadruplet whose sum matches target
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicates for the third number
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        // Skip duplicates for the fourth number
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }

                        // Move both pointers inward to look for other pairs
                        left++;
                        right--;
                    }
                    else if (total < target) {
                        // Sum is too small → need a bigger sum → move left forward
                        left++;
                    }
                    else {
                        // Sum is too large → need a smaller sum → move right backward
                        right--;
                    }
                }
            }
        }

        // Return all unique quadruplets that sum to the target
        return result;
    }
};
