#include "dd_matrix_operations.h"


void sum_matrix( dd_matrix * m1, dd_matrix * m2, dd_matrix * r ) 
{

    if( !m1 || !m2 || !r ) return;
    if( ( ( m1->row != m2->row ) || ( m1->row != r->row ) ) || ( ( m1->col != m2->col ) || ( m1->col != r->col ) ) ) return;


    for( matrix_dimension i = 0; i < m1->row; ++i )
        for( matrix_dimension j = 0; j < m1->col; ++j )
            APE( r, i, j ) = APE( m1, i, j ) + APE( m2, i, j );

}

void diff_matrix( dd_matrix * m1, dd_matrix * m2, dd_matrix * r ) 
{

    if( !m1 || !m2 || !r ) return;
    if( ( ( m1->row != m2->row ) || ( m1->row != r->row ) ) || ( ( m1->col != m2->col ) || ( m1->col != r->col ) ) ) return;


    for( matrix_dimension i = 0; i < m1->row; ++i )
        for( matrix_dimension j = 0; j < m1->col; ++j )
            APE( r, i, j ) = APE( m1, i, j ) - APE( m2, i, j );

}