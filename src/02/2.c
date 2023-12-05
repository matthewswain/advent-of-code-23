#include "parser.h"

int day_02_part_2(char* data) {
    int totalPower = 0;

    Game* games = parse(data);

    Game* currentGame = games;
    while (currentGame) {
        int red = 0;
        int green = 0;
        int blue = 0;

        Round* round = currentGame->rounds;
        while (round) {
            if (round->red > red) red = round->red;
            if (round->green > green) green = round->green;
            if (round->blue > blue) blue = round->blue;
            round = round->next;
        }
        totalPower += (red * green * blue);
        currentGame = currentGame->next;
    }

    freeGame(games);
    return totalPower;
}
