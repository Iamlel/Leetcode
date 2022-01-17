int cmpFunc(const int* a, const int* b)
{
    return (*b - *a);
}

int largestPerimeter(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpFunc);
    int large, small;
    for (int i = 0; i < numsSize - 2; i++) {
        large = nums[i], small = (nums[i + 1] + nums[i + 2]);
        if (small > large) { return (small + large); }
    }
    return 0;
}

/*
Faster

int largestPerimeter(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpFunc);
    for (int i = 0; i < numsSize - 2; i++) {
        if ((nums[i + 1] + nums[i + 2]) > nums[i]) { return (nums[i + 1] + nums[i + 2] + nums[i]); }
    }
    return 0;
}


*/
