//Jal Maru EECS 348 Lab 05 code 2
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
//functions for add multiply transpose and print
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    if (SIZE != SIZE) {
        printf("Error: Matrices are not compatible for multiplication.\n");
        return;
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void transposeMatrix(int m[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = m[i][j];
        }
    }
}

void printMatrix(int m[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int m1[SIZE][SIZE] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
    int m2[SIZE][SIZE] = {{25, 24, 23, 22, 21}, {20, 19, 18, 17, 16}, {15, 14, 13, 12, 11}, {10, 9, 8, 7, 6}, {5, 4, 3, 2, 1}};

    int result_add[SIZE][SIZE];
    int result_multiply[SIZE][SIZE];
    int result_transpose[SIZE][SIZE];
    int result_transpose2[SIZE][SIZE];
//
    addMatrices(m1, m2, result_add);
    multiplyMatrices(m1, m2, result_multiply);
    transposeMatrix(m1, result_transpose);
    transposeMatrix(m2, result_transpose2);
//printing all info from functions
    printf("Matrix 1:\n");
    printMatrix(m1);
    printf("Matrix 2:\n");
    printMatrix(m2);
    printf("Sum of Matrices:\n");
    printMatrix(result_add);
    printf("Product of Matrices:\n");
    printMatrix(result_multiply);
    printf("Transpose of Matrix 1:\n");
    printMatrix(result_transpose);
    printf("Transpose of Matrix 2: \n");
    printMatrix(result_transpose2);

    return 0;
}