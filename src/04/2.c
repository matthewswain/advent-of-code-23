#include <stdlib.h>
#include <string.h>
#include "../shared/main.h"
#include "shared.h"

int day_04_part_2(char* data) {
    char* copy = copyString(data);

    int lineCount = countLines(data);
    int* matches = malloc(sizeof(int) * lineCount);
    int* copies = malloc(sizeof(int) * lineCount);

    char* line = strtok(copy, "\n");
    for (int i = 0; line; i++) {
        matches[i] = matchesOnCard(line);
        line = strtok(NULL, "\n");
    }

    // set one copy of each card to begin
    for (int i = 0; i < lineCount; i++) copies[i] = 1;

    for (int i = 0; i < lineCount; i++) {
        for (int j = 1; j <= matches[i]; j++) {
            if (j < lineCount) copies[i + j] += copies[i]; 
        }
    }

    int total = 0;
    for (int i = 0; i < lineCount; i++) total += copies[i];

    free(matches);
    free(copies);

    return total;
}
