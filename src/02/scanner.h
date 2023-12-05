#ifndef SCANNER_H
#define SCANNER_H

enum TokenTypes {
    TOKEN_GAME,
    TOKEN_RED,
    TOKEN_GREEN,
    TOKEN_BLUE,
    TOKEN_COMMA,
    TOKEN_SEMICOLON,
    TOKEN_COLON,
    TOKEN_NEWLINE,
    TOKEN_EOF,

    TOKEN_NUMBER,
};

typedef struct Token {
    enum TokenTypes type;
    int value;
    struct Token* next;
} Token;

Token* scan(char* s);

void freeToken(Token* t);

#endif
