#include <ctype.h>
#include <stdlib.h>

int isSymbol(char c) {
    if (c == '.') return 0;
    return ispunct(c);
}

int day_03_part_1(char* data) {
    int partNumberTotal = 0;

    int lineLength = 0;
    for (;;) {
        if (data[lineLength] == '\n') break;
        lineLength++;
    }
    lineLength++; // include newline
    
    int totalLength = 0;
    for (;;) {
        if (data[totalLength] == '\0') break;
        totalLength++;
    }
    totalLength++; // include null character

    int partNumber = 0;
    int isPart = 0;
    char buf[2];

    for (int i = 0;; i++) {
        if (data[i] == '\0') break;

        int above = i - lineLength;
        int left = i - 1;
        int right = i + 1;
        int below = i + lineLength;

        int above_left = above - 1;
        int above_right = above + 1;
        int below_left = below - 1;
        int below_right = below + 1;

        if (isdigit(data[i])) {
            buf[0] = data[i];
            buf[1] = '\0';
            partNumber = partNumber * 10 + atoi(buf);
            if (
                (above > 0 && isSymbol(data[above])) ||
                (left > 0 && isSymbol(data[left])) ||
                (below < totalLength && isSymbol(data[below])) ||
                (right < totalLength && isSymbol(data[right])) ||

                (above_left > 0 && isSymbol(data[above_left])) ||
                (above_right > 0 && isSymbol(data[above_right])) ||
                (below_left < totalLength && isSymbol(data[below_left])) ||
                (below_right < totalLength && isSymbol(data[below_right]))
            ) {
                isPart = 1;
            }

            if (!isdigit(data[i + 1])) {
                if (isPart) partNumberTotal += partNumber;
                partNumber = 0;
                isPart = 0;
            }
        }
    }

    return partNumberTotal;
}

