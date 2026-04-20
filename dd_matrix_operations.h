#ifndef DD_MATRIX_OPERATIONS_H
#define DD_MATRIX_OPERATIONS_H

#include "dd_matrix.h"

#define ACCESS_ELEMENT( m, x, y ) ( (m).p[ (x) * (m).col + (y) ] )
#define AE( m, x, y ) ( (m).p[ (x) * (m).col + (y) ] )
#define ACCESS_POINTED_ELEMENT( m, x, y ) ( (m)->p[ (x) * (m)->col + (y) ] ) 
#define APE( m, x, y ) ( (m)->p[ (x) * (m)->col + (y) ] ) 

void sum_matrix( dd_matrix *, dd_matrix *, dd_matrix * );

#endif