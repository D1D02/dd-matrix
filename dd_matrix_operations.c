#include "dd_matrix_operations.h"

/* Matrix operations */
dd_error dd_sum_matrix( dd_matrix * m1, dd_matrix * m2, dd_matrix * r ) 
{

    if( !m1 || !m2 || !r ) return MATRIX_NULL_POINTER;
    if( ( ( m1->row != m2->row ) || ( m1->row != r->row ) ) || ( ( m1->col != m2->col ) || ( m1->col != r->col ) ) ) 
        return ILLEGAL_DIMENSION;


    for( matrix_dimension i = 0; i < m1->row; ++i )
        for( matrix_dimension j = 0; j < m1->col; ++j )
            APE( r, i, j ) = APE( m1, i, j ) + APE( m2, i, j );

    return OK;

}

dd_error dd_diff_matrix( dd_matrix * m1, dd_matrix * m2, dd_matrix * r ) 
{

    if( !m1 || !m2 || !r ) return MATRIX_NULL_POINTER; 
    if( ( ( m1->row != m2->row ) || ( m1->row != r->row ) ) || ( ( m1->col != m2->col ) || ( m1->col != r->col ) ) ) 
        return ILLEGAL_DIMENSION;


    for( matrix_dimension i = 0; i < m1->row; ++i )
        for( matrix_dimension j = 0; j < m1->col; ++j )
            APE( r, i, j ) = APE( m1, i, j ) - APE( m2, i, j );
    
    return OK;

}

/* Utility */
dd_error dd_print_matrix( dd_matrix * m ) 
{

    for( matrix_dimension i = 0; i < m->row; ++i )
    {    
        for( matrix_dimension j = 0; j < m->col; ++j )
        {
            printf( PRI_MATRIX_TYPE " \t",  APE( m, i, j ) );
        }

        printf( "\r\n" );
    
    }

}