#include <ctype.h>
#include <string.h>

char *to_jaden_case (char *jaden_case, const char *string)
{
  size_t len = strlen(string);// strlen will return the length of the string without the null terminator
  
  jaden_case[0] = toupper(string[0]);// toupper will convert the character to uppercase
  
  for (size_t i = 1; i < strlen(string); i++)
  {
    if (string[i - 1] == ' ')
    {
      jaden_case[i] = toupper(string[i]);
    }
    else
    {
      jaden_case[i] = string[i];
    }
  }
  jaden_case[len] = '\0';
  return jaden_case;
}