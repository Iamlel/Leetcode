bool kLengthApart(int* nums, int numsSize, int k) {
    int length = k;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i])) {
            if (length < k) {
                return false;
            }
            length = 0;
        } else {
            length++;
        }
    }
    return true;
}