#include <stddef.h> // NULL
#include <stdlib.h>
#include <string.h>

//returned buffer should be dynamically allocated and will be freed by a caller
char* solution(const char *camelCase) {
  int s = 0;

  // Count the number of uppercase letters
  for (int i = 0; i < strlen(camelCase); i++) {
    if (camelCase[i] >= 'A' && camelCase[i] <= 'Z')
      s++;
  }
  
  // Allocate memory for the result, the size of the camelCase string plus the number of uppercase letters
  char *result = (char *)malloc(sizeof(char) * (strlen(camelCase) + s + 1));

  int j = 0;
  for (unsigned long i = 0; i < strlen(camelCase); i++) {
    if (camelCase[i] >= 'A' && camelCase[i] <= 'Z') 
        result[j++] = ' ';
    result[j++] = camelCase[i];
  }

  result[j] = '\0';
  return result;
}