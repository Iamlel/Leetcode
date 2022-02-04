bool threeConsecutiveOdds(int* arr, int arrSize){
    int tot = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 != 0) {  tot += 1;   }
        else {    tot = 0;    }
        if (tot == 3) { return true;    }
    }
    return false;
}
