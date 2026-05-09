#include <stdio.h>
#include "dd_matrix_operations.h"

#define ROWS 3
#define COLS 3

static matrix_type data0[ROWS * COLS]; 
static matrix_type data1[ROWS * COLS]; 
static matrix_type data2[ROWS * COLS]; 
static matrix_type data3[ROWS * COLS]; 

dd_matrix matrix0 = {
    .p = data0,
    .row = ROWS,
    .col = COLS
};

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

dd_matrix matrix3 = {
    .p = data3,
    .row = ROWS,
    .col = COLS
};

void main( void )
{

    printf("1.Test for matrix initialization.\n\r");
    printf("1.1.Matrix filled with 10.\n\r");
    dd_init_matrix( &matrix0, 10 );
    dd_print_matrix( &matrix0 );

    printf("1.2.Identity Matrix.\n\r");
    dd_init_identity_matrix( &matrix0 );
    dd_print_matrix( &matrix0 );


    printf("1.3.Example Matrix.\n\r");
    for( matrix_dimension i = 0; i < matrix1.row; i++ ) 
        for( matrix_dimension j = 0; j < matrix1.col; j++ )
        { 
            ACCESS_ELEMENT( matrix1, i, j ) = i * matrix2.row + j;
            AE( matrix2, i, j ) = i * matrix2.row + j;
        }
    

    printf("The element (1,1) is: %f\r\n", ACCESS_ELEMENT( matrix1, 1, 1 ) );


    printf("\r\n2.Test for matrices sum and difference.\n\r");
    dd_sum_matrix( &matrix1, &matrix2, &matrix2);
    printf("The element (1,1) is: %f\r\n", AE( matrix2, 1, 1 ) );
    dd_diff_matrix( &matrix2, &matrix1, &matrix2);
    printf("The element (1,1) is: %f\r\n", AE( matrix2, 1, 1 ) );


    printf("3.Test for matrix multiplication.\n\r");
    printf("3.1.Identical Matrices.\n\r");
    dd_init_matrix( &matrix3, 0 );
    dd_mul_matrix( &matrix2, &matrix1, &matrix3 );
    dd_print_matrix( &matrix3 );
    printf("3.2.Identity Matrix.\n\r");
    dd_init_matrix( &matrix3, 0 );
    dd_mul_matrix( &matrix2, &matrix0, &matrix3 );
    dd_print_matrix( &matrix3 );
    

}