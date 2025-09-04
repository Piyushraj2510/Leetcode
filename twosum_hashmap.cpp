#include <vector>  
#include <algorithm> 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        vector<int> ans;  // to store the answer indices

        // First pass: store all numbers with their indices
        for (int i = 0; i < nums.size(); i++) {
            seen[nums[i]] = i;
        }

        // Second pass: look for the complement
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (seen.count(complement) && seen[complement] != i) {
                ans.push_back(i);
                ans.push_back(seen[complement]);
                return ans;
                 // return the filled ans vector
            }
        }

        return ans;// empty if not found (but LeetCode guarantees a solution)
    }
};
