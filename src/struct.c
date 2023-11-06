#include <stdlib.h>
#include <stdio.h>

#include "../include/struct.h"

bool is_empty(Stack* stack) {
    return !(stack->cur_size);
}

int get_length(Stack* st) {
    return st->cur_size;
}

Error create_stack(Stack* st) {
    st->cur_size = 0;
    st->stack = (int*)malloc(sizeof(int) * ALLOCATION_PATERN);
    if (!(st->stack)) {
        st->max_size = 0;
        return MEMORY_ERROR;
    }
    st->max_size = ALLOCATION_PATERN;
    return OK;
}

Error add_value(Stack* st, int value) {
    if (st && !(st->stack)) {
        return MEMORY_ERROR;
    }
    if (st->cur_size == st->max_size) {
        Error err = resize_stack(st);
        if (err != OK) {
            return err;
        }
    }
    st->stack[st->cur_size] = value;
    st->cur_size++;
    return OK;
}

Error resize_stack(Stack* st) {
    if (st && !(st->stack)) {
        return MEMORY_ERROR;
    }
    int* temp = st->stack;
    temp = (int*)realloc(temp, st->max_size + ALLOCATION_PATERN);
    if (!(st->stack)) {
        free_stack(st);
        return MEMORY_ERROR;
    }
    st->max_size += ALLOCATION_PATERN;
    return OK;
}

Error pop_node(Stack* st, int* value) {
    if (is_empty(st)) {
        return EMPTY_STACK;
    }
    *value = st->stack[st->cur_size - 1];
    st->cur_size--;
    return OK;
}

Error get_head(Stack* st, int* value) {
    if (is_empty(st)) {
        return EMPTY_STACK;
    }
    *value = st->stack[st->cur_size - 1];
    return OK;
}

void free_stack(Stack* st) {
    if (st) {
        free(st->stack);
        st->cur_size = 0;
        st->max_size = 0;
    }
}

void print_stack(Stack* st) {
    if (is_empty(st)) {
        printf("[] <- HEAD\n");
        return;
    }
    putchar('[');
    for (int i = 0; i < st->cur_size - 1; i++) {
        printf("%d, ", st->stack[i]);
    }
    printf("%d] <- HEAD\n", st->stack[st->cur_size - 1]);
}

Error reverse_head(Stack* st) {
    if (get_length(st) <= 1) {
        return EMPTY_STACK;
    }
    int temp = st->stack[st->cur_size - 2];
    st->stack[st->cur_size - 2] = st->stack[st->cur_size - 1];
    st->stack[st->cur_size - 1] = temp;
    return OK;
}

void print_err(Error err) {
    fprintf(stderr, "rpn: ");
    switch (err) {
        case DIV_ERROR:
            fprintf(stderr, "divide by 0\n");
            break;
        case MEMORY_ERROR:
            fprintf(stderr, "error while allocating memory\n");
            break;
        case INT_OVERFLOW:
            fprintf(stderr, "int overflow\n");
            break;
        case NEG_NUMBER_ERROR:
            fprintf(stderr, "factorial of negative number\n");
            break;
        case NON_NUMERIC_VALUE:
            fprintf(stderr, "unrecognized token\n");
            break;
        case EMPTY_STACK:
            fprintf(stderr, "stack empty\n");
            break;
        case UNKNOWN_OPERATOR:
            fprintf(stderr, "unknown operator\n");
            break;
        default:
            fprintf(stderr, "unknown error\n");
    }
}
