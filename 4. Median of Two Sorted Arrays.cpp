#include <vector>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int x = nums1.size();
        int y = nums2.size();
        int start = 0;
        int end = x;

        while (start <= end) {
            int partitionX = (start + end) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;

            double maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            double minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

            double maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            double minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((x + y) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
                } else {
                    return max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) {
                end = partitionX - 1;
            } else {
                start = partitionX + 1;
            }
        }

        throw std::invalid_argument("Input arrays are not sorted");
    }
};
