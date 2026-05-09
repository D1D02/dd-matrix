#ifndef DD_MATRIX_OPERATIONS_H
#define DD_MATRIX_OPERATIONS_H

#include "stdio.h"

#include "dd_matrix.h"
#include "dd_matrix_error.h"

#define ACCESS_ELEMENT( m, x, y ) ( (m).p[ (x) * (m).col + (y) ] )
#define AE( m, x, y ) ( (m).p[ (x) * (m).col + (y) ] )
#define ACCESS_POINTED_ELEMENT( m, x, y ) ( (m)->p[ (x) * (m)->col + (y) ] ) 
#define APE( m, x, y ) ( (m)->p[ (x) * (m)->col + (y) ] ) 

/* Matrix initialization */
dd_error dd_init_matrix( dd_matrix *, matrix_type );

/* Matrix operations */
dd_error dd_sum_matrix( dd_matrix *, dd_matrix *, dd_matrix * );
dd_error dd_diff_matrix( dd_matrix *, dd_matrix *, dd_matrix * );

/* Utility */
dd_error dd_print_matrix( dd_matrix * );

#endif