#include "dd_matrix_operations.h"


/* Matrix initialization */
dd_error dd_init_matrix( dd_matrix * m, matrix_type val ) 
{

    if( !m ) return MATRIX_NULL_POINTER;
    if( !val ) val = 0;

    for( matrix_dimension i = 0; i < m->row; ++i )
        for( matrix_dimension j = 0; j < m->col; ++j )
            APE( m, i, j ) = val;

    return OK;

}

dd_error dd_init_identity_matrix( dd_matrix * m )
{

    if( !m ) return MATRIX_NULL_POINTER;

    for( matrix_dimension i = 0; i < m->row; ++i )
        for( matrix_dimension j = 0; j < m->col; ++j )
        {

            if( i == j ){ APE( m, i, j ) = 1; }
            else{ APE( m, i, j ) = 0; }

        }

    return OK;

}

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

dd_error dd_mul_matrix( dd_matrix * m1, dd_matrix * m2, dd_matrix * r )
{

    if( !m1 || !m2 || !r ) return MATRIX_NULL_POINTER; 
    if( ( m1->col != m2->row ) || ( m1->row != r->row ) || ( m2->col != r->col ) ) 
        return ILLEGAL_DIMENSION;

    for( matrix_dimension i = 0; i < m1->row; ++i )
        for( matrix_dimension k = 0; k < m1->col; ++k )
            for( matrix_dimension j = 0; j < m2->col; ++j )
                APE( r, i, j ) = APE( r, i, j ) + APE( m1, i, k ) * APE( m2, k, j );

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

    return OK;

}