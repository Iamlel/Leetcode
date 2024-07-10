int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int largestPerimeter(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    for (int i = 0; i < numsSize - 2; i++) {
        if ((nums[i + 1] + nums[i + 2]) > nums[i]) {
            return (nums[i + 1] + nums[i + 2] + nums[i]);
        }
    }
    return 0;
}
