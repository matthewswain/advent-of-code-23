#ifndef PARSER_H
#define PARSER_H

typedef struct Round {
    int red;
    int green;
    int blue;
    struct Round* next;
} Round;

typedef struct Game {
    int number;
    struct Round* rounds;
    struct Game* next;
} Game;

void freeGame(Game* r);

Game* parse(char* data);

#endif
