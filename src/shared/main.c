#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readFile(char* path) {
    FILE *fp;
    fp = fopen(path, "r");

    fseek(fp, 0, SEEK_END);
    int len = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *content = malloc(len);
    fread(content, 1, len, fp);

    fclose(fp);

    return content;
}

char* copyString(char* input) {
    int length = 1;
    while (input[length - 1] != '\0') length++;
    char* copy = malloc(length + 1);
    strncpy(copy, input, length);
    return copy;
}
