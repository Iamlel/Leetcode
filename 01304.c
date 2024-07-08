int* sumZero(int n, int* returnSize) {
    int* arr = malloc(n * sizeof(int));
    if (n == 2) {
        arr[0] = -1;
        arr[1] = 1;

    } else {
        for (int i = 0; i < n-1; i++) {
            arr[i] = -i;
        }
        arr[n-1] = 1 + (n * (n - 3) >> 1);
    }

    *returnSize = n;
    return arr;
}