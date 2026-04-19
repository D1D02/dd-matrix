#include <stdio.h>
#include "dd_matrix_operations.h"

#define ROWS 2
#define COLS 2

static matrix_type data1[ROWS * COLS]; 
static matrix_type data2[ROWS * COLS]; 

dd_matrix matrix1 = {
    .p = data1,
    .row = ROWS,
    .col = COLS
};

dd_matrix matrix2 = {
    .p = data2,
    .row = ROWS,
    .col = COLS
};

void main( void )
{
    printf("1.Test for matrix initialization.\n\r");
    for( matrix_dimension i = 0; i < matrix1.row; i++ ) 
        for( matrix_dimension j = 0; j < matrix1.col; j++ )
        { 
            ACCESS_ELEMENT( matrix1, i, j ) = i * j + j;
            ACCESS_ELEMENT( matrix2, i, j ) = i * j + j;
        }
    

    printf("The element (1,1) is: %f\r\n", ACCESS_ELEMENT( matrix1, 1, 1 ) );

    printf("\r\n2.Test for matrices sum.\n\r");
    sum_matrix( &matrix1, &matrix2, &matrix2);
    printf("The element (1,1) is: %f\r\n", ACCESS_ELEMENT( matrix2, 1, 1 ) );
}