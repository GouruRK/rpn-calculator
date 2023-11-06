#include <math.h>
#include <stdlib.h>

#include "../include/operators.h"
#include "../include/struct.h"

Error add(int a, int b, int* res) {
    long temp = a + b;
    if (temp != (*res = a + b)) {
        return INT_OVERFLOW;
    }
    return OK;
}

Error sub(int a, int b, int* res) {
    long temp = a - b;
    if (temp != (*res = a - b)) {
        return INT_OVERFLOW;
    }
    return OK;
}

Error mul(int a, int b, int* res) {
    long temp = a * b;
    if (temp != (*res = a * b)) {
        return INT_OVERFLOW;
    }
    return OK;
}

Error divi(int a, int b, int* res) {
    if (!b) {
        return DIV_ERROR;
    }
    long temp = a / b;
    if (temp != (*res = a / b)) {
        return INT_OVERFLOW;
    }
    return OK;
}

Error mod(int a, int b, int* res) {
    if (!b) {
        return DIV_ERROR;
    }
    long temp = ((a % b) + b) % b;
    if (temp != (*res = ((a % b) + b) % b)) {
        return INT_OVERFLOW;
    }
    return OK;
}

Error fac(int a, int* res) {
    if (a < 0) {
        return NEG_NUMBER_ERROR;
    }
    long temp = 1;
    int r;
    for (int i = 1; i <= a; i++) {
        r = temp *= i;
        if (r != temp) {
            return INT_OVERFLOW;
        }
    }
    *res = r;
    return OK;
}

Error expo(int a, int b, int* res) {
    double r = pow(a, b);
    *res = r;
    if (r != *res) {
        return INT_OVERFLOW;
    }
    return OK;
}

binary_op get_binary_compute_function(BinaryOperators ope) {
    switch (ope) {
        case ADD:
            return add;
        case SUB:
            return sub;
        case MUL:
            return mul;
        case DIV:
            return divi;
        case MOD:
            return mod;
        case EXP:
            return expo;
        default:
            return NULL;
    }
}

unary_op get_unary_compute_function(UnaryOperators ope) {
    return ope == FAC ? fac: NULL;
}
