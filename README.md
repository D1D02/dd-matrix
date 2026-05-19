# **DD Matrix**

A comprehensive matrix library with a lot of personalization, intended in context where static allocation is needed. 

I'm a computer science student and I'm developing this to help me in my project, but I want to maintain this library as long is necessary: so feel free, to issue and propose or to report errors.

> [!NOTE]
> This is a student project and is maintained only by the creator himself.

> [!WARNING]
> This library could have problems that are not resolved: in that case, open an issue if it's not already opened.


## Testing

For testing purpose, you can find an example.c file where you can test the library: you will find examples for commands. If you are on linux, you can just use this command to build the code:
```
make
```
And for running the example code, after launching the make command, you just need to send this command:
```
./example
```


## Functions 

In this section you will find all the functions that are implemented on the branch main, with a small explanation.

### Operations
- *dd_sum_matrix**, a function that takes in two addends matrices and one result matrix, and the addition is stored in result matrix.
- *dd_diff_matrix**, a function that takes in two addends matrices and one result matrix, and the subtraction is stored in result matrix.
- *dd_mul_matrix**, a function that takes in two factor matrices and one result matrix, and the multiplication is stored in result matrix.
- *dd_scal_mul_matrix**, a function that takes in a matrix, a scalar and one result matrix, and the scalar multiplication is stored in result matrix.
- *dd_trans_matrix**, a function that takes in an input matrix and one result matrix, and the transpose is stored in result matrix.
- *dd_inv_matrix**, a function that takes in an input matrix and one result matrix, and the inverse is stored in result matrix.

### Utility
- *dd_print_matrix**, a function that takes in an input matrix and print the matrix on the standard output.

### Matrix Initialization
- *dd_init_matrix‎**, a function that takes in an input matrix and a scalar, and the input matrix is initialized with the scalar value.
- *dd_init_identity_matrix‎‎**, a function that takes in an input matrix, and the input matrix is transformed in an identity matrix.

Revisioned by [@antonio-petrillo](https://github.com/antonio-petrillo)
