#include <ctype.h>
#include <stdlib.h>

int startOfNumber(char* data, int ptr) {
    while (isdigit(data[ptr]) && ptr > 0 && isdigit(data[ptr - 1])) {
        ptr--;
    }
    return ptr;
}

int getNumber(char* data, int ptr) {
    ptr = startOfNumber(data, ptr);

    int total = 0;
    char buf[2] = {'\0', '\0'};
    while (isdigit(data[ptr])) {
        buf[0] = data[ptr];
        total = total * 10 + atoi(buf);
        ptr++;
    }

    return total;
}

struct Neighbours {
    int count;
    int first;
    int second;
};

void updateNeighbours(char* data, int len, int ptr, struct Neighbours* neighbours) {
    ptr = startOfNumber(data, ptr);

    if (ptr >= 0 && ptr < len && isdigit(data[ptr])) { 
        if (neighbours->count == 0) {
            neighbours->first = ptr;
            neighbours->count++; 
        }
        else if (neighbours->count == 1 && neighbours->first != ptr) {
            neighbours->second = ptr;
            neighbours->count++;
        }
        else if (neighbours->first != ptr && neighbours->second != ptr) {
            neighbours->count++; 
        }
    }
}

int day_03_part_2(char* data) {
    int total = 0;

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

    struct Neighbours* neighbours = malloc(sizeof(struct Neighbours));

    for (int i = 0;; i++) {
        if (data[i] == '\0') break;

        neighbours->count = 0;

        int above = i - lineLength;
        int left = i - 1;
        int right = i + 1;
        int below = i + lineLength;

        int above_left = above - 1;
        int above_right = above + 1;
        int below_left = below - 1;
        int below_right = below + 1;

        if (data[i] == '*') {
            updateNeighbours(data, totalLength, above, neighbours);
            updateNeighbours(data, totalLength, left, neighbours);
            updateNeighbours(data, totalLength, right, neighbours);
            updateNeighbours(data, totalLength, below, neighbours);
            updateNeighbours(data, totalLength, above_left, neighbours);
            updateNeighbours(data, totalLength, above_right, neighbours);
            updateNeighbours(data, totalLength, below_left, neighbours);
            updateNeighbours(data, totalLength, below_right, neighbours);

            if (neighbours->count == 2) {
                total += getNumber(data, neighbours->first) * getNumber(data, neighbours->second);
            }
        }
    }

    free(neighbours);

    return total;
}
