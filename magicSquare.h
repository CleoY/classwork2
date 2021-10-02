#ifndef MAGICSQUARE_H
#define MAGICSQUARE_H

int checkRow(int square[][3]);
int checkCol(int square[][3]);
int checkLeftToRightDiagonal(int square[][3]);
int checkRightToLeftDiagonal(int square[][3]);
int checkValidSquare(int square[][3]);
int printSquare(int square[][3]);
int createSquare(int square[][3]);
int checkDuplicates(int square[][3]);

#endif