#ifndef DD_MATRIX_OPERATIONS_H
#define DD_MATRIX_OPERATIONS_H

#include "stdio.h"

#include "dd_matrix.h"
#include "dd_matrix_error.h"

#define MATRIX_2x2_INVERSION //Comment this line if you don't need 2x2 matrix inversion

#define ACCESS_ELEMENT( m, x, y ) ( (m).p[ (x) * (m).col + (y) ] )
#define AE( m, x, y ) ( (m).p[ (x) * (m).col + (y) ] )
#define ACCESS_POINTED_ELEMENT( m, x, y ) ( (m)->p[ (x) * (m)->col + (y) ] ) 
#define APE( m, x, y ) ( (m)->p[ (x) * (m)->col + (y) ] ) 

/* Matrix initialization */
dd_error dd_init_matrix( dd_matrix *, matrix_type );
dd_error dd_init_identity_matrix( dd_matrix * );

/* Matrix operations */
dd_error dd_sum_matrix( dd_matrix *, dd_matrix *, dd_matrix * );
dd_error dd_diff_matrix( dd_matrix *, dd_matrix *, dd_matrix * );
dd_error dd_mul_matrix( dd_matrix *, dd_matrix *, dd_matrix * );
dd_error dd_scal_mul_matrix( dd_matrix *, matrix_type );
dd_error dd_trans_matrix( dd_matrix *, dd_matrix * );
dd_error dd_inv_matrix( dd_matrix *, dd_matrix * );


void dd_forward_substitution( matrix_type *, matrix_type *, matrix_dimension, matrix_dimension );
void dd_backward_substitution( matrix_type *, matrix_type *, matrix_type *, matrix_dimension );

/* Utility */
dd_error dd_print_matrix( dd_matrix * );

#endif