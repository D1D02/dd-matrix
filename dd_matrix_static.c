#include "dd_matrix_static.h"


dd_matrix identity_3 = {
    .p = (matrix_type[]){1, 0, 0, 0, 1, 0, 0, 0, 1},
    .row = 3,
    .col = 3
};

dd_matrix inverse_3 = {
    .p = (matrix_type[]){2, 1, 1, 4, -6, 0, -2, 7, 2},
    .row = 3,
    .col = 3
};