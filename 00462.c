int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int minMoves2(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    double median = (numsSize % 2) ? nums[numsSize >> 1] : (nums[numsSize >> 1] + nums[numsSize - 1 >> 1 ]) * 0.5;

    double moves = 0;
    for (int i = 0; i < numsSize; i++) {
        moves += fabs(nums[i] - median);
    }
    return moves;
}