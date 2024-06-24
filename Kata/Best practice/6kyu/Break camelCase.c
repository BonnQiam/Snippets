#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char *solution(const char *camelCase)
{
  int in_len = strlen(camelCase);
  char *output = calloc(in_len * 2, sizeof(char));

  for (int i = 0, k = 0; i < in_len; i++, k++)
  {
     if (i >= 1 && isupper(camelCase[i]))// isupper() is a function in ctype.h, which checks if a character is an uppercase letter
     {
        output[k] = ' ';
        k++;
     }
     output[k] = camelCase[i];
  }
  
  return output;
}