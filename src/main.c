#include <stdio.h>
#include <stdlib.h>
#include "01/1.h"
#include "01/2.h"
#include "02/1.h"
#include "02/2.h"
#include "03/1.h"
#include "03/2.h"
#include "04/1.h"
#include "shared/main.h"

int main() {
    char* day_01_data = readFile("data/01");
    printf("01/1: %d\n", day_01_part_1(day_01_data));
    printf("01/2: %d\n\n", day_01_part_2(day_01_data));
    free(day_01_data);

    char* day_02_data = readFile("data/02");
    printf("02/1: %d\n", day_02_part_1(day_02_data));
    printf("02/2: %d\n\n", day_02_part_2(day_02_data));
    free(day_02_data);

    char* day_03_data = readFile("data/03");
    printf("03/1: %d\n", day_03_part_1(day_03_data));
    printf("03/2: %d\n\n", day_03_part_2(day_03_data));
    free(day_03_data);

    char* day_04_data = readFile("data/04");
    printf("04/1: %d\n", day_04_part_1(day_04_data));
    free(day_04_data);
}
