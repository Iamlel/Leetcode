int largestPerimeter(int* nums, int numsSize) {
    qsort(nums, numsSize); // sort in descending order
    int large, small;
    for (int i = 0; i < numsSize - 2; i++) {
        large = nums[i], small = (nums[i + 1] + nums[i + 2]);
        if (small > large) { return (small + large); }
    }
    return 0;
}
