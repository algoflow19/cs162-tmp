#include<stdlib.h>
#include<stdio.h>

int square(int x);

int main(int argc, char *argv[]) {
    printf("This program will square an integer.\n");

    // the program should have one number as an argument
    if (argc != 2) {
        printf("Usage:\n\t./square number\n");
        return 0;
    }

    // the first argument after the filename
    int numToSquare = atoi(argv[1]);

    int squaredNum = square(numToSquare);

    printf("%d squared is %d\n",numToSquare,squaredNum);

    return 0;
}


int square(int x) {
    int sq = x * x;
    return sq;
}
