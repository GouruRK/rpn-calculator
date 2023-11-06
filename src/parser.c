#include <stdbool.h>
#include <stdlib.h>

#include "../include/struct.h"
#include "../include/tools.h"

char* split(char* str) {
    // The general idea of this function is to imitate python's implementation of generators
    // This function 'split' tokens depending on the separators (see is_separator)
    // The function doesnt really split : it modifies the begining and ending of `str`
    // You can reset the statics variables by setting `str` NULL
    static int start = 0;
    static int end = 0;
    static char c = -1;
    if (!str) {
        start = 0;
        end = 0;
        c = -1; 
        return NULL;
    }
    if (c != -1) {
        str[end] = c;
        end++;
        start = end;
        c = -1;
    }
    if (str[end] == '\0') {
        start = end;
    }
    while (str[end] != '\0') {
        if (is_separator(str[end])) {
            c = str[end];
            str[end] = '\0';
            return str + start;
        }
        end++;
    }
    if (end != start) {
        return str + start;
    } else {
        return NULL;
    }
}

Error char_to_int(char* to_cast, int* res) {
    int i = 0;
    *res = 0;
    long int keep = 0;
    int sign = -1;
    while ((*res >= 0) && (to_cast[i] != '\0') && (keep == *res)) {
        if (to_cast[i] == '-' && i == 0) {
            sign = 1;
        } else if ('0' <= to_cast[i] && to_cast[i] <= '9') {
            *res *= 10;
            *res += to_cast[i] - '0';
            keep *= 10;
            keep += to_cast[i] - '0';
        } else {
            return NON_NUMERIC_VALUE;
        }
        i++;
    }
    if (keep != *res) {
        return INT_OVERFLOW;
    }
    *res = (-1 * sign) * *res;
    return OK;
}
