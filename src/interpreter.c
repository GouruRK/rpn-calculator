#include <stdio.h>

#include "../include/operators.h"
#include "../include/struct.h"
#include "../include/compute.h"

Error calculate_bin(Stack* st, BinaryOperators operator) {
    if (get_length(st) < 2) {
        return EMPTY_STACK;
    }
    binary_op fbin = get_binary_compute_function(operator);
    if (!fbin) {
        return UNKNOWN_OPERATOR;
    }
    int a, b, res;
    Error err;
    if ((err = pop_node(st, &b)) != OK) {
        return err;
    }
    if ((err = pop_node(st, &a)) != OK) {
        add_value(st, b);
        return err;
    }
    if ((err = fbin(a, b, &res)) != OK) {
        add_value(st, a);
        add_value(st, b);
        return err;
    }
    if ((err = add_value(st, res)) != OK) {
        add_value(st, a);
        add_value(st, b);
        return err;
    }
    return OK;
}

Error calcultate_un(Stack* st, UnaryOperators operator) {
    if (is_empty(st)) {
        return EMPTY_STACK;
    }
    unary_op fun = get_unary_compute_function(operator);
    if (!fun) {
        return UNKNOWN_OPERATOR;
    }
    Error err;
    int a, res;
    if ((err = pop_node(st, &a)) != OK) {
        return err;
    }
    if ((err = fun(a, &res)) != OK) {
        add_value(st, a);
        return err;
    }
    if ((err = add_value(st, res)) != OK) {
        add_value(st, a);
        return err;
    }
    return OK;
}

Error interpret_command(Stack* st, Commands command) {
    Error err;
    int value;
    switch (command) {
        case QUIT:
            return EXIT;
        case PRINT:
            if ((err = get_head(st, &value)) != OK) {
                return err;
            }
            printf("%d\n", value);
            return OK;
        case CLEAR:
            st->cur_size = 0;
            return OK;
        case ALL:
            print_stack(st);
            return OK;
        case REVERSE:
            return reverse_head(st);
        default:
            return OK;
    }
}
