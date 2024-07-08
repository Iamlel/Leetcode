int differenceOfSums(int n, int m) {
    return (n * (n + 1) >> 1) - m * (n / m) * ((n / m) + 1); 
}