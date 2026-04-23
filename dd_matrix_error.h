#ifndef DD_MATRIX_ERROR_H
#define DD_MATRIX_ERROR_H


typedef enum {
    OK,
    MATRIX_NULL_POINTER,
    ILLEGAL_DIMENSION, //Matrices dimensions are not correct
} dd_error;

#endif