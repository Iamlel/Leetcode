#define byte char
bool threeConsecutiveOdds(int* arr, int arrSize){
    byte total = 0;
    for (int i = 0; i < arrSize; i++) {
        total = (arr[i] % 2) ? total + 1 : 0;
        if (total == 3) {
            return true;
        }
    }
    return false;
}
