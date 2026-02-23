#include <assert.h>
#include <stddef.h>
#include "str.h"


size_t Str_getLength(const char pcSrc[])
{
   size_t uLength = 0;

   assert(pcSrc != NULL);

   while (pcSrc[uLength] != '\0')
      uLength++;
   return uLength;
}

char *Str_copy(char *pcDest, const char *pcSrc)
{
   size_t uIndex = 0;

   assert(pcDest != NULL);
   assert(pcSrc != NULL);

   while (pcSrc[uIndex] != '\0')
   {
      pcDest[uIndex] = pcSrc[uIndex];
      uIndex++;
   }
   pcDest[uIndex] = '\0';
   return pcDest;
}

char *Str_concat(char *pcDest, const char *pcSrc) 
{
    size_t uIndex = 0;
    size_t uDestLength; 
    
    assert(pcDest != NULL);
    assert(pcSrc != NULL);
    
    uDestLength = Str_getLength(pcDest);

    while (pcSrc[uIndex] != '\0') {
        pcDest[uDestLength + uIndex] = pcSrc[uIndex];
        uIndex++;
    }
    pcDest[uDestLength + uIndex] = '\0';
    return pcDest;
}

int Str_compare(const char *pcS1, const char *pcS2)
{
   size_t uIndex = 0;

   assert(pcS1 != NULL);
   assert(pcS2 != NULL);

   while (pcS1[uIndex] != '\0' && pcS2[uIndex] != '\0')
   {
      if (pcS1[uIndex] < pcS2[uIndex])
         return -1;
      else if (pcS1[uIndex] > pcS2[uIndex])
         return 1;
      uIndex++;
   }
   if (pcS1[uIndex] == '\0' && pcS2[uIndex] == '\0')
      return 0;
   else if (pcS1[uIndex] == '\0')
      return -1;
   else
      return 1;
}

char *Str_search(const char *pcHaystack, const char *pcNeedle)
{
   size_t uHayStackLength;
   size_t uNeedleLength;
   size_t i;
   size_t j;

   assert(pcHaystack != NULL);
   assert(pcNeedle != NULL);

   uHayStackLength = Str_getLength(pcHaystack);
   uNeedleLength = Str_getLength(pcNeedle);

   if (uNeedleLength == 0) {
      return (char *)&pcHaystack[0];
   }
   if (uNeedleLength > uHayStackLength) {
      return NULL;
   }
   for (i = 0; i < uHayStackLength - uNeedleLength + 1; i++) {
      j = 0;
      while (j < uNeedleLength && (pcHaystack[i + j] == pcNeedle[j])) {
         j++;
      }
      if (j == uNeedleLength) {
         return (char *)(&pcHaystack[i]);
      }
   }
    return NULL;
}