#include <stdio.h>

int is_valid_ip(const char *addr)
{
 unsigned n[4], i, nc;
 
 // Must be 4 integers separated by dots:
 if( sscanf(addr, "%d.%d.%d.%d%n", &n[0], &n[1], &n[2], &n[3], &nc) != 4 )
   return 0;
   
 // Leftover characters at the end are not allowed:
 if( nc != strlen(addr) )
   return 0;
   
 // Leading zeros and space characters are not allowed:
 if( addr[0] == '0' || strstr(addr, ".0") || strchr(addr, ' ') )
   return 0;
 
 // Values > 255 are not allowed:
 for(i=0; i<4; i++)
   if( n[i] > 255 )
     return 0;
  
 return 1;
};