char* categorizeBox(int length, int width, int height, int mass) {
    switch ((mass >= 100) + (length >= 1e4 || width >= 1e4 || height >= 1e4 || (long long) length * width * height >= 1e9)) {
        case 2:
            return "Both";

        case 1:
            return (mass >= 100) ? "Heavy" : "Bulky";

        case 0:
            return "Neither";
    }   
    return NULL;
}