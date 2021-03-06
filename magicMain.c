#include "magicSquare.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//cd GIT/classwork2/
//gcc magicSquare.c magicMain.c -o magicMain

int main(){

    int invalidMagicSquare[3][3] = { {8,2,5},
                                     {2,5,8},
                                     {5,8,2} };
    
    int anotherValidSquare [3][3] = { {4,9,2},
                                 {3,5,7},
                                 {8,1,6} };

    //VALID square example
    int validMagicSquare[3][3];
    createSquare(validMagicSquare);
    printSquare(validMagicSquare);

    int validSquareCheck = checkValidSquare(validMagicSquare) + checkDuplicates(validMagicSquare);

    if (validSquareCheck == 2){
        printf("First square is valid\n");
    } else{
        printf("First square is NOT valid\n");
    }

    //INvalid square example
    printSquare(invalidMagicSquare);
    validSquareCheck = checkValidSquare(invalidMagicSquare) + checkDuplicates(invalidMagicSquare);

    if (validSquareCheck == 2){
        printf("Second square is valid\n");
    } else{
        printf("Second square is NOT valid\n");
    }

    //Another valid square
    printSquare(anotherValidSquare);
    validSquareCheck = checkValidSquare(anotherValidSquare) + checkDuplicates(anotherValidSquare);

    if (validSquareCheck == 2){
        printf("3rd square is valid\n");
    } else{
        printf("3rd square is NOT valid\n");
    }
}