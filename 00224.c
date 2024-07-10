#define byte char

int recursiveCalculate(char *s, int *j) {
    int answer = 0;

    byte op = 1;
    unsigned int operand = 0;

    for (int i = 0; ; i++) {
        switch(s[i]) {
            case ' ':
                break;

            case '-':
                if (operand) {
                    answer += operand * op;
                    operand = 0;
                }
                op = -1;
                break;

            case '+':
                answer += operand * op;
                op = 1;
                operand = 0;
                break;

            case '(':
                i++;
                operand = recursiveCalculate(s + i, j);
                i += *j;
                break;

            case ')':
                *j = i;
            case '\0':
                return answer + operand * op;

            default:
                operand *= 10;
                operand += s[i] - 48;
        }     
    }
    return -1;
}

int calculate(char* s) {
    int j;
    return recursiveCalculate(s, &j);
}