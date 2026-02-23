
/* check if we have already seen this file.
   if not, define it. */
#ifndef STR_H
#define STR_H

/* include the standard library for definition 
    of size_t */
#include <stddef.h> 

/* * Str_getLength returns the length of string pcSrc.
 * Behavior is equivalent to standard C function strlen.
 */
size_t Str_getLength(const char *pcSrc);

/* * Str_copy copies the string pointed to by pcSrc (including 
 * the null byte) to the buffer pointed to by pcDest.
 * Behavior is equivalent to standard C function strcpy.
 */
char *Str_copy(char *pcDest, const char *pcSrc);

/* * Str_concat appends the pcSrc string to the pcDest string, 
 * overwriting the terminating null byte at the end of pcDest, 
 * and then adds a terminating null byte.
 * Behavior is equivalent to standard C function strcat.
 */
char *Str_concat(char *pcDest, const char *pcSrc);

/* * Str_compare compares the two strings pcS1 and pcS2. 
 * It returns an integer less than, equal to, or greater than zero 
 * if pcS1 is found, respectively, to be less than, to match, 
 * or be greater than pcS2.
 * Behavior is equivalent to standard C function strcmp.
 */
int Str_compare(const char *pcS1, const char *pcS2);

/* * Str_search finds the first occurrence of the substring pcNeedle 
 * in the string pcHaystack. The terminating null bytes are not compared.
 * Behavior is equivalent to standard C function strstr.
 */
char *Str_search(const char *pcHaystack, const char *pcNeedle);

#endif