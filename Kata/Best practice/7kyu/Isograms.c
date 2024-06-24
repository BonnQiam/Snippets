#include <stdbool.h>

bool IsIsogram(char *str) {
    char cache[26] = {0};
    // cache is an array of 26 elements, each element is a char type, and the initial value is 0
    
    for (int i = 0; str[i] != 0; ++i) {
      char c = tolower(str[i]) - 'a';
      
      if (cache[c]) 
        return false;// when the character is in the cache, means the character is repeated, return false
      
      cache[c] = 1;// when the character is not in the cache, set the corresponding element to 1
    }

    return str[0] == 0 || true; 
    // if the string is empty, return true
    // if the string is not empty and the characters in the string are all different, return true
}