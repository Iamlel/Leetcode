int totalMoney(int n) {
    // sum of natural numbers manipulation
    int remainder = n % 7;
    int div = n / 7;
    return remainder * (remainder + 1) * 0.5 + div * remainder + 3.5 * div * (div + 7);  
}