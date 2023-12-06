#include <ctype.h>
#include <string.h>
#include "../shared/main.h"
#include "shared.h"

int day_04_part_1(char* data) {
    int total = 0;

    char* copy = copyString(data);
    char* line = strtok(copy, "\n");

    while (line) {
        Node* have = NULL;
        Node* winners = NULL;

        // remove "Card"
        shiftString(line, 5);
        takeSpace(line);

        // remove card number
        takeNumber(line);

        // remove ":"
        shiftString(line, 1);

        takeSpace(line);
        while (isdigit(line[0])) {
            int value = takeNumber(line);
            Node* n = newNode(value);
            winners = addNode(winners, n);
            takeSpace(line);
        }

        // remove "|"
        shiftString(line, 1);

        takeSpace(line);
        while (isdigit(line[0])) {
            int value = takeNumber(line);
            Node* n = newNode(value);
            have = addNode(have, n);
            takeSpace(line);
        }

        int matchCount = countMatches(winners, have);

        int points = 0;
        while (matchCount) {
            if (points == 0) points = 1;
            else points = points * 2;
            matchCount--;
        }

        total += points;

        line = strtok(NULL, "\n");
    }

    return total;
}

