/*--------------------------------------------------------------------*/
/* strp.c                                                             */
/* Author: Brooke Xu                                                  */
/*                                                                    */
/* A pointer-based implementation of the custom string library.       */
/*--------------------------------------------------------------------*/
#include <assert.h>
#include <stddef.h>
#include "str.h"

size_t Str_getLength(const char *pcSrc)
{
   const char *pcEnd;
   assert(pcSrc != NULL);
   pcEnd = pcSrc;
   while (*pcEnd != '\0')
      pcEnd++;
   return (size_t)(pcEnd - pcSrc);
}

char *Str_copy(char *pcDest, const char *pcSrc)
{
   char *pcDestStart = pcDest;
   assert(pcDest != NULL);
   assert(pcSrc != NULL);

   while (*pcSrc != '\0') {
      *pcDest = *pcSrc;
      pcDest++;
      pcSrc++;
   }
   *pcDest = '\0';
   return pcDestStart;
}

char *Str_concat(char *pcDest, const char *pcSrc) 
{
    char *pcDestStart = pcDest;
    assert(pcDest != NULL);
    assert(pcSrc != NULL);
    
    while (*pcDest != '\0') {
        pcDest++;
    }
    
    while (*pcSrc != '\0') {
      *pcDest = *pcSrc;
      pcDest++;
      pcSrc++;
    }
    *pcDest = '\0';
    return pcDestStart;
}

int Str_compare(const char *pcS1, const char *pcS2)
{
   assert(pcS1 != NULL);
   assert(pcS2 != NULL);

   while (*pcS1 != '\0' && *pcS2 != '\0') {
      if (*pcS1 < *pcS2)
         return -1;
      else if (*pcS1 > *pcS2)
         return 1;
      pcS1++;
      pcS2++;
   }
   if (*pcS1 == '\0' && *pcS2 == '\0')
      return 0;
   else if (*pcS1 == '\0')
      return -1;
   else
      return 1;
}

char *Str_search(const char *pcHaystack, const char *pcNeedle)
{
    assert(pcHaystack != NULL);
    assert(pcNeedle != NULL);

   /* If needle is empty, return haystack */
   if (*pcNeedle == '\0')
      return (char *)pcHaystack;

   while (*pcHaystack != '\0') {
        const char *pcH = pcHaystack;
        const char *pcN = pcNeedle;
        
        while (*pcH != '\0' && *pcN != '\0' && *pcH == *pcN) {
            pcH++;
            pcN++;
        }
        
        if (*pcN == '\0') {
            return (char *)pcHaystack;
        }
        
        pcHaystack++;
    }
    return NULL;
}