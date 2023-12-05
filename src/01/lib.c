#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int intFromDigit(char input[]) {
    if (isdigit(input[0]) == 1) {
        char str[2] = {input[0], '\0'}; 
        return atoi(str);
    }
    return -1;
}

int intFromWord(char input[]) {
    char numberWords[10][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for (int i = 0; i < 10; i++) {
        if (strstr(input, numberWords[i]) == input) return i;
    }
    return -1;
}

int intFromDigitOrWord(char input[]) {
    int fromDigit = intFromDigit(input);
    if (fromDigit > -1) return fromDigit;
    return intFromWord(input);
}
