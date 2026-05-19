#ifndef DD_MATRIX_H
#define DD_MATRIX_H

typedef float matrix_type; //This can be modified with the wanted type
typedef unsigned short int matrix_dimension; //This need to be modified only if you want matrices to be larger than 65535x65535 (use unsigned)

#define PRI_MATRIX_TYPE "%.3f"

typedef struct DD_MATRIX {
    matrix_type *p;
    matrix_dimension row;
    matrix_dimension col;
}dd_matrix;



#endif 