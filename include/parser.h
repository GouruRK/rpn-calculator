#ifndef __INIT_PARSER__
#define __INIT_PARSER__

#include "struct.h"

/**
 * @brief Split the given string according on separators. 
 *        It returns a sub sequence of the string. Once all 
 *        the string has been parsed, it returns NULL. 
 *        To reset the function, set the parameter to NULL 
 *        before give it another string.  
 * 
 * @param str string to split
 * @return char* sub sequence of the string
 */
char* split(char* str);

/**
 * @brief Convert a string to an int.
 * 
 * @param to_cast string to cas
 * @param res result
 * @return NON_NUMERIC_VALUE if the string contains char that are non numeric,
 *         INT_OVERFLOW if the string contains a value smaller than INT_MIN or 
 *          greater than MAX_INT, as defined in <limits.h>,
 *         else OK
 */
Error char_to_int(char* to_cast, int* res);

#endif
