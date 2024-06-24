#include <stdbool.h>
#include <string.h>

// We will use a stack to store the opening braces
// When we encounter a '(', '[', '{', we push them into the stack
// When we encounter a ')', ']', '}', we pop the stack and check if they match
// If they don't match, return false
// If the stack is not empty at the end, return false

bool valid_braces (const char *braces)
{
	size_t len = strlen(braces);
	char *stack = (char *)malloc(len*sizeof(char));
	int stack_index = -1;

	// Not a balanced brace string if we have an odd number of chars
	if (len % 2 != 0) 
        return false;

	for (size_t i=0; i<len; i++) {
		switch (braces[i]) {
            // For'(', '[' and '{', push them into the stack
			case '(': case '[': case '{':
				stack[++stack_index] = braces[i]; break;

            // For')', ']' and '}', pop the stack and check if they match
			case ')':
				if (stack[stack_index] != '(') return false; 
				else stack[stack_index--] = '\0'; break;
			case ']':
				if (stack[stack_index] != '[') return false; 
				else stack[stack_index--] = '\0'; break;
			case '}':
				if (stack[stack_index] != '{') return false; 
				else stack[stack_index--] = '\0'; break;
		}
	}
	return stack_index == -1; // Stack must be empty
}