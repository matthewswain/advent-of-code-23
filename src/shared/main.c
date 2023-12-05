#include <stdio.h>
#include <stdlib.h>

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
