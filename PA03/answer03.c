#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "answer03.h"

char * strcat_ex(char * * dest, int * n, const char * src){
  if(*n < strlen(*dest) + strlen(src)){
    char* buffer;
    buffer = malloc(1 + 2 * (strlen(*dest) + strlen(src)));
    *n = strlen(buffer);
    strcpy(buffer,*dest);
    free(*dest);
    *dest = buffer;
  }
    strcat(*dest,src);
    return *dest;
}

char * * explode(const char * str, const char * delims, int * arrLen){
  *arrLen = 0;
  while(*str){
    while(*delims){
      if(strchar(str,*delims) != NULL){
	*arrLen++;
	
      }
    }
  }

}
