#include "../shared/main.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shiftString(char* s, int len) {
    for (int i = 0;; i++) {
        s[i] = s[i + len];
        if (s[i] == '\0') break;
    }
}

int takeNumber(char* s) {
    int taken = 0;
    int number = 0;
    char buf[2] = {'\0', '\0'};

    while (isdigit(s[taken])) {
        buf[0] = s[taken];
        number = number * 10 + atoi(buf);
        taken++;
    }

    shiftString(s, taken);
    return number;
}

void takeSpace(char* s) {
    int len = 0;
    while (isspace(s[len])) len++;
    shiftString(s, len);
}

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* newNode(int value) {
    Node* new = malloc(sizeof(Node));
    new->next = NULL;
    new->value = value;
    return new;
}

void freeNode(Node* n) {
    if (n->next) freeNode(n->next);
    free(n);
}

Node* addNode(Node* existing, Node* new) {
    if (!existing) {
        return new;
    }

    if (new->value < existing->value) {
        new->next = existing;
        return new;
    }

    Node* prev = NULL;
    Node* next = existing;
    while (next) {
        if (new->value < next->value) {
            new->next = next;
            prev->next = new;
            return existing;
        }

        prev = next;
        next = next->next;
    }

    prev->next = new;
    return existing;
}

int countMatches(Node* a, Node* b) {
    int count = 0;

    while (a && b) {
        if (a->value == b->value) {
            count++;
            a = a->next;
            b = b->next;
            continue;
        }
        if (a->value < b->value) {
            a = a->next;
            continue;
        }
        b = b->next;
    }

    return count;
}

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

