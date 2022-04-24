// Multiplying two matrices
//
// Filename:  deöetefromarray.c
// Chapter:   1
// Page:      18-19
// Created:   2022-04-25
// Uppdated:  2022-04-25
// Edited by: Niklas Engvall

// Orginal code example by Bintu Harwani, from the book Practical C Programming, 1st ed, feb 2020.
// 
// Description: This example multiplies two matrices, 2 x 3 and 3 x 4 to a 2 x 4 matrix
// 
// 
// 
// 

#include <stdio.h>

int main(void)
{
    // Variable declarations
    int matrix_1[2][3], matrix_2[3][4], result_matrix[2][4];
    
    int i, j, k;
    
    // Let the user input the values of the matrices
    // First matrix to input 
    printf("Enter elements of first matrix of order 2 x 3: \n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%d", (*(matrix_1 + i) + j));
        }
    }
  
    // Second matrix to input 
    printf("Enter elements of second matrix of order 3 x 4: \n");
    for( i = 0; i < 3; i++) {
        for(j = 0; j < 4; j++) {
            scanf("%d", (*(matrix_2 + i) + j));
        }
    }
  
    // Calculate all the multiplies to a 2 x 4 matrix
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 4; j++) {
            *(*(result_matrix + i) + j) = 0;    // Sets the value to 0
            for(k = 0; k < 3; k++) {
                *(*(result_matrix + i) + j) += *(*(matrix_1 + i) + k) * *(*(matrix_2 + k) + j);
            }
        }
    }
  
    printf("\nFirst Matrix is: \n");
    for( i = 0; i < 2; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d\t", *(*(matrix_1 + i) + j));
        }
        printf("\n");
    }
  
    printf("\nSecond Matrix is: \n");
    for(i = 0;i < 3; i++) {
        for(j = 0; j < 4; j++) {
            printf("%d\t", *(*(matrix_2 + i) + j));
        }
        printf("\n");
    }
  
    printf("\nMatrix multiplication is: \n"); 
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 4; j++) {
            printf("%d\t", *(*(result_matrix + i) + j));
        }
        printf("\n");
    }
    return 0;
}