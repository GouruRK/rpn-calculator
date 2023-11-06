#ifndef __INIT_TOOLS__
#define __INIT_TOOLS__

#include <stdbool.h>

#include "operators.h"
#include "struct.h"

/**
 * @brief Check if the given char is related to an unary operator.
 * 
 * @param ope unary operator symbol
 * @return true if the char is related to an unary operator,
 *         else false
 */
bool is_un_operator(char ope);

/**
 * @brief Check if the given char is related to a binary operator.
 * 
 * @param ope binary operator symbol
 * @return true if the char is related to a binary operator,
 *         else false
 */
bool is_bin_operator(char ope);

/**
 * @brief Check if the given char is a separator.
 * 
 * @param ope separator symbol
 * @return true if the char is a separator,
 *         else false
 */
bool is_separator(char sep);

/**
 * @brief Check if the given char is related to a command.
 * 
 * @param ope command symbol
 * @return true if the char is related to a commands,
 *         else false
 */
bool is_command(char c);

#endif
