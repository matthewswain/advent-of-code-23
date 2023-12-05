#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"

int wordLength(char* s) {
    for (int i = 0;; i++) {
        if (s[i] == '\0') return i;
        if (isalpha(s[i])) continue;
        return i;
    }
} 

int numberLength(char* s) {
    for (int i = 0;; i++) {
        if (s[i] == '\0') return i;
        if (isdigit(s[i])) continue;
        return i;
    }
}

int tokenLength(char* c) {
    if (isdigit(*c)) return numberLength(c);
    if (isalpha(*c)) return wordLength(c);
    if (*c == ':' || *c == ';' || *c == ',' || *c == '\n' || *c == '\0') return 1;
    return -1;
}

char* substring(char* s, int len) {
    char* ss = malloc(len + 1);
    memset(ss, '\0', len + 1);
    memcpy(ss, s, len);
    return ss;
}

void freeToken(Token* t) {
    if (t->next) freeToken(t->next);
    free(t);
}

Token* scan(char* s) {
    // skip spaces
    int ptr = 0;
    while (s[ptr] == ' ') {
        ptr++;
    }

    int len = tokenLength(s + ptr);
    if (len == -1) return NULL;

    char* value = substring(s + ptr, len);

    Token* token = malloc(sizeof(Token));

    if (strcmp(value, "Game") == 0) token->type = TOKEN_GAME;
    if (strcmp(value, "red") == 0) token->type = TOKEN_RED;
    if (strcmp(value, "green") == 0) token->type = TOKEN_GREEN;
    if (strcmp(value, "blue") == 0) token->type = TOKEN_BLUE;
    if (strcmp(value, ",") == 0) token->type = TOKEN_COMMA;
    if (strcmp(value, ";") == 0) token->type = TOKEN_SEMICOLON;
    if (strcmp(value, ":") == 0) token->type = TOKEN_COLON;
    if (strcmp(value, "\n") == 0) token->type = TOKEN_NEWLINE;
    if (strcmp(value, "\0") == 0) token->type = TOKEN_EOF;
    
    if (isdigit(value[0])) {
        token->type = TOKEN_NUMBER;
        token->value = atoi(value);
    }
    
    free(value);

    if (token->type != TOKEN_EOF) {
        token->next = scan(s + ptr + len);
    }

    return token;
}
