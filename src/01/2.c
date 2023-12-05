#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int day_01_part_2(char* data) {
    int total = 0;

    char *line = strtok(data, "\n");

    int first, last;

    while (line) {
        first = '\0';
        last = '\0';

        for (int ptr = 0;; ptr++) {
            if (line[ptr] == '\0') {
                char buf[3];
                sprintf(buf, "%d%d", first, last);
                total += atoi(buf);
                break;
            }

            int number = intFromDigitOrWord(&line[ptr]);
            if (number == -1) continue;

            if (first == '\0') first = number;
            last = number;
        }

        line = strtok(NULL, "\n");
    }

    return total;
}
