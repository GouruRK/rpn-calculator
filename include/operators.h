#ifndef __INIT_OPERATORS__
#define __INIT_OPERATORS__

// defining operators

#define NB_BIN_OPERATORS 6

typedef enum {
    ADD = '+',
    SUB = '-',
    MUL = '*',
    DIV = '/',
    MOD = '%',
    EXP = '^',
} BinaryOperators;

#define NB_UN_OPERATORS 1

typedef enum {
    FAC = '!'
} UnaryOperators;

// defining comands

#define NB_COMMANDS 5

typedef enum {
    QUIT    = 'q',
    PRINT   = 'p',
    CLEAR   = 'c',
    ALL     = 'a',
    REVERSE = 'r',
} Commands;

// defining separators

#define NB_SEPARATORS 4

typedef enum {
    SPAC  = ' ',
    TABU  = '\t',
    NLINE = '\n',
    BACK  = '\r'
} Separators;

typedef enum {
    BIN_OPERATOR,
    UN_OPERATOR,
    COMMAND,
    SEPARATOR,
    NUMBER
} Instruction;

#endif
