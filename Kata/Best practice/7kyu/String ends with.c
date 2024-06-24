#include <stdbool.h>
#include <string.h>

bool solution(const char *string, const char *ending)
{
    int len = strlen(string) - strlen(ending);
    return len < 0 ?false :strcmp(string + len, ending) == 0; 
    // strcmp will compare two strings, the input is the address of the first character of the string and the address of the first character of the second string
}