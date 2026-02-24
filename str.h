
/* check if we have already seen this file.
   if not, define it. */
#ifndef STR_H
#define STR_H

/* include the standard library for definition 
    of size_t */
#include <stddef.h> 

/* Return the length of string pcSrc, 
   not including the trailing '\0'.*/
size_t Str_getLength(const char *pcSrc);

/* Copy string pcSrc (including the trailing '\0') 
   to string pcDest. Return pcDest.  */
char *Str_copy(char *pcDest, const char *pcSrc);

/* Append string pcSrc to end of string pcDest 
   (overwriting pcDest's trailing '\0', then add 
   a trailing '\0' to the updated pcDest. Return pcDest. */
char *Str_concat(char *pcDest, const char *pcSrc);

/* Compare strings pcS1 and pcS2. Return integer -1 if pcS1 is 
   less than pcS2. Return 0 if pcS1 is equal to pcS2. 
   Return integer 1 if pcS1 is greater than pcS2. */
int Str_compare(const char *pcS1, const char *pcS2);

/* Search for first occurrence of string pcNeedle in string 
   pcHaystack. Terminating null bytes are not compared. Return 
   pointer to where pcNeedle is found within pcHaystack, or 
   NULL if not found. */
char *Str_search(const char *pcHaystack, const char *pcNeedle);

#endif