#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "magicSquare.h"


//DELETE COMMENTS BEFORE
//CHANGE row CONDITION FROM 3 -> MORE FLEXIBLE

int checkRow(int square[][3]);
int checkCol(int square[][3]);
int checkLeftToRightDiagonal(int square[][3]);
int checkRightToLeftDiagonal(int square[][3]);
int checkValidSquare(int square[][3]);
int printSquare(int square[][3]);
int createSquare(int square[][3]);
int checkDuplicates(int square[][3]);


int createSquare(int square[][3]){
    int squareCreationCount = 0;
    time_t t;
    int valid;

    srand((unsigned) time(&t));
    generateSquare:

    valid = 0;
    for(int r = 0; r < 3; r ++){
        for(int c = 0; c < sizeof(square[0])/sizeof(int); c++){
            //printf("Size of col: %lu\n", sizeof(square[0])/sizeof(int));
            square[r][c] = (rand() % 9) + 1;
            printf("square[%d][%d] = %d\n", r, c, square[r][c]);
        }
    }

    valid = checkValidSquare(square) + checkDuplicates(square);
    printf("Valid: %d; ", valid);
    if(valid != 2){
        printf("Attempt %d failed\n", squareCreationCount);
        squareCreationCount++;
        goto generateSquare;
    }

    printf("Magic square successfully created after %d tries\n", squareCreationCount);
    
    return 0;
}

int checkDuplicates(int square[][3]){
    int temp1DArr[9];
    
    //printf("temp1D size: %lu\n", sizeof(square[0]));
    
    int i = 0;

    for(int squareRow = 0; squareRow < 3; squareRow++){
        for(int squareCol = 0; squareCol < sizeof(square[0])/sizeof(int); squareCol++){
            temp1DArr[i] = square[squareRow][squareCol];
            //printf("temp1D[%d] = %d\n", i, square[squareRow][squareCol]);
            i++;
        }
    }
    
    for(int size1D = 0; size1D < 9 - 1 ; size1D ++){
        for(int indexOfNextValue = size1D + 1; indexOfNextValue < 9; indexOfNextValue++){
            //printf("Compare: %d @ %d  AND  %d @ %d\n", temp1DArr[size1D], size1D, temp1DArr[indexOfNextValue], indexOfNextValue);
            if(temp1DArr[size1D] == temp1DArr[indexOfNextValue]){
                //printf("Duplicates found with %d and %d @ %d and %d\n", temp1DArr[size1D], temp1DArr[indexOfNextValue], size1D,indexOfNextValue);
                return 0;
            }
        }
    }
    return 1;
}


int printSquare(int square[][3]){
    for(int r = 0; r < 3; r++){
        printf("[");
        for(int c = 0; c < sizeof(square[0])/sizeof(int); c++){
            printf("%d ", square[r][c]);
        }
        printf("]\n");
    }
    return 0;
}

int checkRow(int square[][3]){
    int rowSum = 0;
    for(int row = 0; row < 3; row++){
        rowSum = 0;
        //printf("Row size: %lu\n", sizeof(square[0]));
        for(int col = 0; col < sizeof(square[0])/sizeof(int); col++){
            rowSum += square[row][col];
            //printf("Square[%d][%d]: %d, ", row, col, square[row][col]);
        }
        //printf("Sum: %d\n", rowSum);
        if (rowSum != 15)
            return 0;
    }
    return 1;
}


int checkCol(int square[][3]){
    int colSum = 0;
    for(int col = 0; col < sizeof(square[0])/sizeof(int); col++){
        colSum = 0;
        for(int row = 0; row < 3; row++){
            colSum += square[row][col];
        }
        if (colSum != 15)
            return 0;
    }
    return 1;
}


int checkLeftToRightDiagonal(int square[][3]){
    int diagonalSum = 0;
    for(int row = 0; row < 3; row++){
        diagonalSum += square[row][row];
    }
    if(diagonalSum!=15){
        return 0;
    }
    return 1;
}


int checkRightToLeftDiagonal(int square[][3]){
    int diagonalSum = 0;
    int row = 0;
    for(int col = sizeof(square[0])/sizeof(int) - 1; col >= 0; col--){
        //printf("Square[%d][%d]: %d, ", row, col, square[row][col]);
        diagonalSum += square[row][col];
        row++;
    }
    //printf("Sum: %d\n", diagonalSum);
    if(diagonalSum!=15){
        return 0;
    }
    return 1;
}


int checkValidSquare(int square[][3]){
    int validityCount = 0;
    validityCount += checkRow(square);
    validityCount += checkCol(square);
    validityCount += checkLeftToRightDiagonal(square);
    validityCount += checkRightToLeftDiagonal(square);
    return validityCount == 4;
}