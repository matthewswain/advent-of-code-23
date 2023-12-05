#include <stdlib.h>
#include "scanner.h"
#include "parser.h"

Round* newRound() {
    Round* r = malloc(sizeof(Round));
    r->red = 0;
    r->green = 0;
    r->blue = 0;
    r->next = NULL;
    return r;
}

void freeRound(Round* r) {
    if (r->next) freeRound(r->next);
    free(r);
}

Game* newGame() {
    Game* g = malloc(sizeof(Game));
    g->number = -1;
    g->rounds = NULL;
    g->next = NULL;
    return g;
}

void freeGame(Game* g) {
    if (g->next) freeGame(g->next);
    if (g->rounds) freeRound(g->rounds);
    free(g);
}

Game* parse(char* data) {
    Game* firstGame = NULL;

    Game* currentGame = NULL;
    Round* currentRound = NULL;

    Token* first = scan(data);
    Token* current = first;

    while (current) {
        switch (current->type) {
            case TOKEN_GAME: {
                Game* nextGame = newGame();

                if (!firstGame) firstGame = nextGame;
                else currentGame->next = nextGame;

                nextGame->rounds = newRound();
                currentRound = nextGame->rounds;

                nextGame->number = current->next->value;
                current = current->next;

                currentGame = nextGame;
                break;
            }

            case TOKEN_NUMBER: {
                switch (current->next->type) {
                    case TOKEN_RED: currentRound->red = current->value; break;
                    case TOKEN_GREEN: currentRound->green = current->value; break;
                    case TOKEN_BLUE: currentRound->blue = current->value; break;
                    default: break;
                }
                break;
            }

            case TOKEN_SEMICOLON: {
                Round* nextRound = newRound();
                currentRound->next = nextRound;
                currentRound = nextRound;
                break;
            }

            default: break;
        }

        current = current->next;
    }

    freeToken(first);
    return firstGame;
}
