#include "dd_matrix_operations.h"


/* Matrix initialization */
dd_error dd_init_matrix( dd_matrix * m, matrix_type val ) 
{

    if( !m ) return MATRIX_NULL_POINTER;
    if( !val ) val = 0;

    for( register matrix_dimension i = 0; i < m->row; ++i )
        for( register matrix_dimension j = 0; j < m->col; ++j )
            APE( m, i, j ) = val;

    return OK;

}

dd_error dd_init_identity_matrix( dd_matrix * m )
{

    if( !m ) return MATRIX_NULL_POINTER;

    for( register matrix_dimension i = 0; i < m->row; ++i )
        for( register matrix_dimension j = 0; j < m->col; ++j )
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


    for( register matrix_dimension i = 0; i < m1->row; ++i )
        for( register matrix_dimension j = 0; j < m1->col; ++j )
            APE( r, i, j ) = APE( m1, i, j ) + APE( m2, i, j );

    return OK;

}

dd_error dd_diff_matrix( dd_matrix * m1, dd_matrix * m2, dd_matrix * r ) 
{

    if( !m1 || !m2 || !r ) return MATRIX_NULL_POINTER; 
    if( ( ( m1->row != m2->row ) || ( m1->row != r->row ) ) || ( ( m1->col != m2->col ) || ( m1->col != r->col ) ) ) 
        return ILLEGAL_DIMENSION;


    for( register matrix_dimension i = 0; i < m1->row; ++i )
        for( register matrix_dimension j = 0; j < m1->col; ++j )
            APE( r, i, j ) = APE( m1, i, j ) - APE( m2, i, j );
    
    return OK;

}

dd_error dd_mul_matrix( dd_matrix * m1, dd_matrix * m2, dd_matrix * r )
{

    if( !m1 || !m2 || !r ) return MATRIX_NULL_POINTER; 
    if( ( m1->col != m2->row ) || ( m1->row != r->row ) || ( m2->col != r->col ) ) 
        return ILLEGAL_DIMENSION;
    
    dd_init_matrix(r, 0);

    for( register matrix_dimension i = 0; i < m1->row; ++i )
        for( register matrix_dimension k = 0; k < m1->col; ++k )
            for( register matrix_dimension j = 0; j < m2->col; ++j )
                APE( r, i, j ) = APE( r, i, j ) + APE( m1, i, k ) * APE( m2, k, j );

    return OK;   

}

dd_error dd_scal_mul_matrix( dd_matrix * m, matrix_type val ) 
{
    if( !m ) return MATRIX_NULL_POINTER; 
    if( !val ) val = 0;

    for( register matrix_dimension i = 0; i < m->row; ++i )
        for( register matrix_dimension j = 0; j < m->col; ++j )
            APE( m, i, j ) = val * APE( m, i, j );

    return OK;   

}

dd_error dd_trans_matrix( dd_matrix * m1, dd_matrix * m2 )
{
    if( !m1 || !m2 ) return MATRIX_NULL_POINTER; 
    if( ( m1->row != m2->col ) || ( m1->col != m2->row ) )
        return ILLEGAL_DIMENSION;

    for( register matrix_dimension i = 0; i < m1->row; ++i )
        for( register matrix_dimension j = 0; j < m1->col; ++j )
            APE( m2, j, i ) = APE( m1, i, j );

    return OK;   

}

dd_error dd_inv_matrix( dd_matrix * m, dd_matrix * inv )
{
    if( !m || !inv ) return MATRIX_NULL_POINTER; 
    if( ( m->row != m->col ) || ( m->row != inv->row ) || ( m->col != inv->col ) )
        return ILLEGAL_DIMENSION;

    #ifdef MATRIX_2x2_INVERSION
    if( m->row == 2 )
    {
        matrix_type det = APE( m, 0, 0 ) * APE( m, 1, 1 ) - APE( m, 0, 1 ) * APE( m, 1, 0 );

        APE( inv, 0, 0 ) = APE( m, 1, 1 ); APE( inv, 0, 1 ) = -APE( m, 0, 1 );
        APE( inv, 1, 0 ) = -APE( m, 1, 0 ); APE( inv, 1, 1 ) = APE( m, 0, 0 );

        if( det == 0 ) return NULL_DETERMINANT;

        dd_scal_mul_matrix( inv, 1 / det );

        return OK;
    }
    #endif

    matrix_type l[m->row * m->col]; matrix_type u[m->row * m->col]; 

    for( register matrix_dimension j = 0; j < m->col * m->row; ++j  ) u[j] = m->p[j];
    
    for( register matrix_dimension i = 0; i < m->row; ++i  )
        for( register matrix_dimension j = 0; j < m->col; ++j  ) 
            if( i == j ) l[ i * m->col + j ] = 1; else l[ i * m->col + j ] = 0;

    
    for( register matrix_dimension d = 0; d < m->row - 1; ++d  )
    { 
        matrix_type piv = u[d * m->col + d];
        
        for( register matrix_dimension i = d + 1; i < m->row; ++i  )
        {
            l[ i * m->col + d ] = u[ i * m->col + d ] / piv;
            
            for( register matrix_dimension j = d; j < m->col; ++j ) u[ i * m->col + j ] -= l[ i * m->col + d ] * u[ d * m->col + j ];
        
        } 

    }   

    matrix_dimension n = m->row;

    matrix_type y[n];
    matrix_type x[n];

    for( register matrix_dimension r = 0; r < n; ++r )
    {
        dd_forward_substitution( y, l, r, n );
        dd_backward_substitution( x, y, u, n );

        for( register matrix_dimension i = 0; i < n; ++i )
        {
            APE( inv, i, r ) = x[i];
        }
    }

    /*for( register matrix_dimension i = 0; i < m->row; ++i  )
    {
        for( register matrix_dimension j = 0; j < m->col; ++j  ) 
        {
            printf( PRI_MATRIX_TYPE " \t", u[ i * m->col + j ] );
        }
        printf("\n");
    }*/
    return OK;

}


void dd_forward_substitution( matrix_type * y, matrix_type * L, matrix_dimension r, matrix_dimension n )
{
    for( register matrix_dimension i = 0; i < n; ++i )
    {
        matrix_type b = (i == r) ? 1 : 0;

        matrix_type sum = 0;

        for( register matrix_dimension k = 0; k < i; ++k ) sum += L[ i * n + k ] * y[k];

        y[i] = ( b - sum ) / L[ i * n + i ];
    }
}

void dd_backward_substitution( matrix_type * x, matrix_type * y, matrix_type * U, matrix_dimension n )
{
     for(register matrix_dimension i = n; i > 0; --i)
    {
        matrix_type sum = 0;

        for( matrix_dimension k = i; k < n; ++k )
        {
            sum += U[ ( i - 1 ) * n + k] * x[k];
        }

        x[( i - 1 )] = ( y[( i - 1 )] - sum ) / U[ ( i - 1 ) * n + ( i - 1 ) ];
    }
}

/* Utility */
dd_error dd_print_matrix( dd_matrix * m ) 
{

    for( register matrix_dimension i = 0; i < m->row; ++i )
    {    
        for( register matrix_dimension j = 0; j < m->col; ++j )
        {
            printf( PRI_MATRIX_TYPE " \t",  APE( m, i, j ) );
        }

        printf( "\r\n" );
    
    }

    return OK;

}