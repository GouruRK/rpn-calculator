#ifndef __INIT_STRUCT__
#define __INIT_STRUCT__

#include <stdbool.h>

#include "operators.h"

#define ALLOCATION_PATERN 10

typedef enum {
    DIV_ERROR,
    MEMORY_ERROR,
    INT_OVERFLOW,
    NEG_NUMBER_ERROR,
    NON_NUMERIC_VALUE,
    EMPTY_STACK,
    EXIT,
    UNKNOWN_OPERATOR,
    OK
} Error;

typedef Error (*binary_op)(int, int, int*);
typedef Error (*unary_op)(int, int*);

typedef struct {
    int max_size;
    int cur_size;
    int* stack;
} Stack;

bool is_empty(Stack* stack);

int get_length(Stack* st);

Error create_stack(Stack* st);

Error add_value(Stack* st, int value);

Error resize_stack(Stack* st);

Error pop_node(Stack* st, int* value);

Error get_head(Stack* st, int* value);

void free_stack(Stack* st);

void print_err(Error err);

void print_stack(Stack* st);

Error reverse_head(Stack* st);

#endif
