#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int day_01_part_1(char* data) {
    int total = 0;

    // copy input so it isn't modified by strtok
    int length = 1;
    while (data[length - 1] != '\0') length++;
    char* copy = malloc(length + 1);
    strncpy(copy, data, length);

    char *line = strtok(copy, "\n");

    char first = '\0';
    char last = '\0';

    while (line) {
        for (int i = 0;; i++) {
            if (line[i] == '\0') {
                char number_s[3] = {first, last, '\0'};
                total += atoi(number_s);
                first = '\0';
                last = '\0';
                break;
            }

            if (isdigit(line[i])) {
                if (first == '\0') {
                    first = line[i];
                }
                last = line[i];
            }
        }

        line = strtok(NULL, "\n");
    }

    free(copy);
    return total;
}
