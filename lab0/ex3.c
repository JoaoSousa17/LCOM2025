#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void printBoard(){
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

void printSmallBar(){
    printf("=-=-=-=-=-=-=\n");
}

int main() {
    /*// Primeira Parte
    int n = 0;
    printf("n=%d\n", n);
    n = n | 1;
    printf("n|1=%d\n", n);

    printBoard();

    // Segunda Parte
    printf("0b101^0b10=%d\n", 0b101^0b10);
    printf("0xF+1=%d\n", 0xF+1);

    printBoard();

    // Terceira Parte
    int k = 0xE;
    printf("k=%d\n", k);
    printf("Bit 3 of k is %d\n", (k >> 3) & 1);
    printSmallBar();
    printf("Bit 3 of k is %d\n", (k & 0b1000) >> 3);
    printSmallBar();
    k |= (1 << 3); // k = k | (1 << 3)
    printf("k=%d\n", k);
    printSmallBar();
    k &= ~(1 << 3); // k = k & ~(1 << 3)
    printf("k=%d\n", k);
    printSmallBar();
    #define BIT(n) (1 << (n)) // () prevent precedence issues
    k |= BIT(3); // set bit 3                                                   This doesn´t work!
    k &= ~BIT(3); // clear bit 3                                                This doesn´t work!
    if (k & BIT(3)) foo(); // check if bit 3 is set*/

    printBoard();
    printf("Challenge 1\n");
    printBoard();

    int n = 10;  // Pode ser alterado para qualquer valor
    int i;

    printf("Representacao em bits de n = %d:\n", n);
    for(i = sizeof(n) * CHAR_BIT - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");

    printBoard();
    printf("Challenge 2\n");
    printBoard();

    // TO DO Ex2

    return 0;
}