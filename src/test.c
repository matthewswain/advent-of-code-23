#include "shared/main.h"
#include "01/1.h"
#include "01/2.h"
#include "02/1.h"
#include "02/2.h"
#include "03/1.h"
#include "03/2.h"
#include <stdlib.h>

int result = 0; 

void fail() {
    result = 1;
}

void test_day_01_part_1() {
    char* data = readFile("data/01.1.test");
    int expected = 142;
    int actual = day_01_part_1(data);
    if (expected != actual) fail();
    free(data);
}

void test_day_01_part_2() {
    char* data = readFile("data/01.2.test");
    int expected = 281;
    int actual = day_01_part_2(data);
    if (expected != actual) fail();
    free(data);
}

void test_day_02_part_1() {
    char* data = readFile("data/02.test");
    int expected = 8;
    int actual = day_02_part_1(data);
    if (expected != actual) fail();
    free(data);
}

void test_day_02_part_2() {
    char* data = readFile("data/02.test");
    int expected = 2286;
    int actual = day_02_part_2(data);
    if (expected != actual) fail();
    free(data);
}

void test_day_03_part_1() {
    char* data = readFile("data/03.test");
    int expected = 4361;
    int actual = day_03_part_1(data);
    if (expected != actual) fail();
    free(data);
}

void test_day_03_part_2() {
    char* data = readFile("data/03.test");
    int expected = 467835;
    int actual = day_03_part_2(data);
    if (expected != actual) fail();
    free(data);
}

int main() {
    test_day_01_part_1();
    test_day_01_part_2();

    test_day_02_part_1();
    test_day_02_part_2();

    test_day_03_part_1();
    test_day_03_part_2();

    return result;
}
