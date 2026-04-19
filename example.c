#include <stdio.h>
#include "dd_matrix_operations.h"

#define ROWS 2
#define COLS 2

static matrix_type data[ROWS * COLS]; 

dd_matrix matrix = {
    .p = data,
    .row = ROWS,
    .col = COLS
};

void main( void )
{
    for( matrix_dimension i = 0; i < matrix.row; i++ ) 
        for( matrix_dimension j = 0; j < matrix.col; j++ ) 
            ACCESS_ELEMENT( matrix, i, j ) = i * j + j;

    printf("The element (1,1) is: %f\r\n", ACCESS_ELEMENT( matrix, 1, 1 ) );

}