class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        int i = 0;  // Pointer for nums1
        int j = 0;  // Pointer for nums2
        int total = n1 + n2;  // Total number of elements

        vector<int> merged;
        merged.reserve(total);  // Reserve space to avoid reallocations

        // Merge both sorted arrays into one sorted array
        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i++]);  // Add smaller element and move pointer
            } else {
                merged.push_back(nums2[j++]);
            }
        }

        // If elements left in nums1, add them
        while (i < n1) {
            merged.push_back(nums1[i++]);
        }

        // If elements left in nums2, add them
        while (j < n2) {
            merged.push_back(nums2[j++]);
        }

        double median;

        // If total number of elements is odd, return middle element
        if (total % 2 == 1) {
            median = merged[total / 2];
        }
        // If even, return average of two middle elements
        else {
            median = (merged[(total / 2) - 1] + merged[total / 2]) / 2.0;
        }

        return median;
    }
};
