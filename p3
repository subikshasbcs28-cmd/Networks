#include <stdlib.h>

// Helper function to find the bound
int findBound(int* nums, int numsSize, int target, int isFirst) {
    int left = 0;
    int right = numsSize - 1;
    int bound = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            bound = mid; // Potential bound found
            if (isFirst) {
                right = mid - 1; // Keep searching left for the first occurrence
            } else {
                left = mid + 1;  // Keep searching right for the last occurrence
            }
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return bound;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    // Always set the return size to 2 as we return [start, end]
    *returnSize = 2;
    
    int* result = (int*)malloc(2 * sizeof(int));
    if (result == NULL) {
        return NULL;
    }

    // Edge case: empty array
    if (numsSize == 0 || nums == NULL) {
        result[0] = -1;
        result[1] = -1;
        return result;
    }

    result[0] = findBound(nums, numsSize, target, 1); // Find first occurrence
    
    // If the element doesn't exist, the second search is unnecessary
    if (result[0] == -1) {
        result[1] = -1;
    } else {
        result[1] = findBound(nums, numsSize, target, 0); // Find last occurrence
    }

    return result;
}
