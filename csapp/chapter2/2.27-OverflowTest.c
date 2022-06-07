//
// Created by IanQian on 2022/6/7.
//
#include <stdio.h>
#include <limits.h>

int uadd_ok(unsigned x, unsigned y);

int main() {
    unsigned int y = 1;
    unsigned int x = UINT_MAX - y;
    unsigned int z = 0;
    printf("uadd_ok(%u,%u):%d\n", x, y, uadd_ok(x, y));
    printf("uadd_ok(%u,%u):%d\n", UINT_MAX, y, uadd_ok(UINT_MAX, y));
    printf("uadd_ok(%u,%u):%d\n", UINT_MAX, z, uadd_ok(UINT_MAX, z));
}

int uadd_ok(unsigned int x, unsigned int y) {
    return x + y >= x;
}
