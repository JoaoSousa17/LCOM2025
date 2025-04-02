#include <stdio.h>
#include "helper.h"

int main(void) {
    int x = 3, y = 4;
    printf("The sum of %d and %d is %d\n", x, y, add(x, y));
    return 0;
}
