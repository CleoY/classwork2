#include "magicSquare.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//cd GIT/classwork2/
//gcc magicSquare.c magicMain.c -o magicMain

int main(){

    int magicSquare2 [3][3] = { {4,9,2},
                                {3,5,7},
                                {8,1,6} };

    int magicSquare3 [3][3] = { {8,2,5},
                                {2,5,8},
                                {5,8,2} };

    int magicSquare1[3][3];
    createSquare(magicSquare1);
    printSquare(magicSquare1);
    
    /*
    int valid = checkValidSquare(magicSquare2) + checkDuplicates(magicSquare2);
    printf("Magic square2 valid: %d\n", valid);
    
    valid = checkValidSquare(magicSquare3) + checkDuplicates(magicSquare3);
    printf("Magic square3 valid: %d\n", valid);
    */

/*
    int dup = checkDuplicates(magicSquare3);
    printf("magic3 does NOT have duplicates: %d\n", dup);
*/
    //createSquare();
    //int magicSquare2 [3][3] = createSquare();

    /*
    int rowCheck = checkRow(magicSquare1);
    printf("Row: %d\n",rowCheck);

    int colCheck = checkCol(magicSquare1);
    printf("Col: %d\n",colCheck);

    int leftDiagonalCheck = checkLeftToRightDiagonal(magicSquare1);
    printf("Left diagonal: %d\n",leftDiagonalCheck);

    int rightDiagonalCheck = checkRightToLeftDiagonal(magicSquare1);
    printf("Right diagonal: %d\n", rightDiagonalCheck);

    int validSquareCheck = checkValidSquare(magicSquare1);
    printf("Valid square: %d\n", validSquareCheck);

    if (validSquareCheck == 1){
        printf("Square is valid\n");
    } else{
        printf("Square is NOT valid\n");
    }

    printSquare(magicSquare1);
    */
}