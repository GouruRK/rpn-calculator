#include <stdlib.h>
#include <stdbool.h>
#include <readline/readline.h>

#include "../include/compute.h"
#include "../include/struct.h"
#include "../include/tools.h"
#include "../include/parser.h"
#include "../include/interpreter.h"

Error action(Stack* st, char* token) {
    Error err;
    char c = token[0];
    if (is_un_operator(c) && token[1] == '\0') {
        return calcultate_un(st, c);
    } else if (is_bin_operator(c) && token[1] == '\0') {
        return calculate_bin(st, c);
    } else if (is_command(c) && token[1] == '\0') {
        return interpret_command(st, c);
    } else { // at this point, token is a number or an unvalid token
        int value;
        if ((err = char_to_int(token, &value)) != OK) {
            return err;
        }
        if ((err = add_value(st, value)) != OK) {
            return err;
        }
    }
    return OK;
}

int main(void) {
    Stack st;
    Error err = create_stack(&st);
    if (err != OK) {
        return err;
    }
    char *line = readline(NULL), *token;
    while (line) {
        while ((token = split(line))) {
            if (token[0] == '\0') {
                continue;
            }
            err = action(&st, token);
            if (err != OK) {
                if (err == EXIT) {
                    free(line);
                    free_stack(&st);
                    return 0;
                }
                print_err(err);
            }
        }
        split(NULL);
        free(line);
        line = readline(NULL);
    }
    free_stack(&st);
    return 0;
}
