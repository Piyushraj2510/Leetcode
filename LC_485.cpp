class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int maxlen = 0; // Stores the maximum length of consecutive 1s found so far
        int count = 0;  // Counts the current streak of consecutive 1s

        // Traverse through the array
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1) // If current element is 1
            {
                count++; // Increase current streak length
                maxlen = max(maxlen, count); // Update max length if needed
            }
            else // If current element is 0
            {
                count = 0; // Reset streak count
            }
        }

        // Return the longest streak found
        return maxlen;    
    }
};
