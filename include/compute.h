#ifndef __INIT_COMPUTE__
#define __INIT_COMPUTE__

#include "struct.h"

/**
 * @brief Compute addition 'a+b'. Store the result in `res`.
 * 
 * @param a left operand
 * @param b right operand
 * @param res store the result
 * @return INT_OVERFLOW if `res` is lower than INT_MIN or greather 
 *                      than INT_MAX as defined in <limit.h>
 *         else OK
 */
Error add(int a, int b, int* res);

/**
 * @brief Compute substraction 'a-b'. Store the result in `res`.
 * 
 * @param a left operand
 * @param b right operand
 * @param res store the result
 * @return INT_OVERFLOW if `res` is lower than INT_MIN or greather 
 *                      than INT_MAX as defined in <limit.h>
 *         else OK
 */
Error sub(int a, int b, int* res);

/**
 * @brief Compute multiplication 'a*b'. Store the result in `res`.
 * 
 * @param a left operand
 * @param b right operand
 * @param res store the result
 * @return INT_OVERFLOW if `res` is lower than INT_MIN or greather 
 *                      than INT_MAX as defined in <limit.h>
 *         else OK
 */
Error mul(int a, int b, int* res);

/**
 * @brief Compute division 'a/b'. Store the result in `res`.
 * 
 * @param a left operand
 * @param b right operand
 * @param res store the result
 * @return INT_OVERFLOW if `res` is lower than INT_MIN or greather 
 *                      than INT_MAX as defined in <limit.h>,
 *         DIV_ERROR if `b` is 0,
 *         else OK
 */
Error divi(int a, int b, int* res);

/**
 * @brief Compute modulo 'a%b'. Store the result in `res`.
 * 
 * @param a left operand
 * @param b right operand
 * @param res store the result
 * @return INT_OVERFLOW if `res` is lower than INT_MIN or greather 
 *                      than INT_MAX as defined in <limit.h>,
 *         DIV_ERROR if `b` is 0,
 *         else OK
 */
Error mod(int a, int b, int* res);


/**
 * @brief Compute factorial 'a!'. Store the result in `res`.
 * 
 * @param a left operand
 * @param b right operand
 * @param res store the result
 * @return INT_OVERFLOW if `res` is greather than INT_MAX,
 *                      as defined in <limit.h>,
 *         NEG_NUMBER_ERROR if `a` is negative 
 *         else OK
 */
Error fac(int a, int* res);

/**
 * @brief Compute pow 'a^b'. Store the result in `res`.
 * 
 * @param a left operand
 * @param b right operand
 * @param res store the result
 * @return INT_OVERFLOW if `res` is lower than INT_MIN or greather 
 *                      than INT_MAX, as defined in <limit.h>,
 *         else OK
 */
Error expo(int a, int b, int* res);

/**
 * @brief Get the binary compute function according to its symbol.
 * 
 * @param ope operator symbol
 * @return function that represent the operator,
 *         NULL if the given symbol does not represent an implemented
 *          binary operator
 */
binary_op get_binary_compute_function(BinaryOperators ope);

/**
 * @brief Get the unary compute function according to its symbol.
 * 
 * @param ope operator symbol
 * @return function that represent the operator,
 *         NULL if the given symbol does not represent an implemented 
 *          unary operator
 */
unary_op get_unary_compute_function(UnaryOperators ope);

#endif
