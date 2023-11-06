#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/operators.h"
#include "../include/struct.h"
#include "../include/tools.h"

BinaryOperators bin_operator_array[NB_BIN_OPERATORS] = {ADD, SUB, MUL, DIV, MOD, EXP};
UnaryOperators un_operator_array[NB_UN_OPERATORS] = {FAC};
Commands command_array[NB_COMMANDS] = {QUIT, PRINT, CLEAR, ALL, REVERSE};
Separators separator_array[NB_SEPARATORS] = {SPAC, TABU, NLINE, BACK};

bool is_token(char c, void* array, int size) {
    for (int i = 0; i < size; i++) {
        if (c == ((int*)(array))[i]) {
            return true;
        }
    }
    return false;
}

bool is_un_operator(char c) {
    return is_token(c, un_operator_array, NB_UN_OPERATORS);
}

bool is_bin_operator(char c) {
    return is_token(c, bin_operator_array, NB_BIN_OPERATORS);
}

bool is_separator(char c) {
    return is_token(c, separator_array, NB_SEPARATORS);
}

bool is_command(char c) {
    return is_token(c, command_array, NB_COMMANDS);
}
