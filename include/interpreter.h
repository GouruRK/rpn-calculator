#ifndef __INIT_INTERPRETER__
#define __INIT_INTERPRETER__

#include "struct.h"

/**
 * @brief Compute a binary function given by the `operator`.
 *        Pop the two tops values of the stack, compute them and 
 *        stack the result. In error case, the two popped values are
 *        add on the stack again.
 * 
 * @param st current stack
 * @param operator given operator
 * @return OK in case of success
 *         else the error code
 */
Error calculate_bin(Stack* st, BinaryOperators operator);

/**
 * @brief Compute an unary function given by the `operator`.
 *        Pop the first value of the stack, compute it and 
 *        stack the result. In error case, the popped value
 *        is adding on the stack again
 * 
 * @param st current stack
 * @param operator given operator
 * @return OK in case of success
 *         else the error code
 */
Error calcultate_un(Stack* st, UnaryOperators operator);

/**
 * @brief Interpret a command given by the `command`.
 * 
 * @param st current stack
 * @param operator given command
 * @return OK in case of success,
 *         QUIT to quit the programm,
 *         else the error code
 */
Error interpret_command(Stack* st, Commands command);

#endif
