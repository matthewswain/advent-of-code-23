#include "parser.h"

const int RED = 12;
const int GREEN = 13;
const int BLUE = 14;

int day_02_part_1(char* data) {
    int total = 0;
    Game* games = parse(data);

    Game* currentGame = games;
    while (currentGame) {
        int ok = 1;
        Round* round = currentGame->rounds;
        while (round) {
            if (
                round->red > RED ||
                round->green > GREEN ||
                round->blue > BLUE
            ) {
                ok = 0;
            }
            round = round->next;
        }
        if (ok == 1) total += currentGame->number;
        currentGame = currentGame->next;
    }

    freeGame(games);
    return total;
}
