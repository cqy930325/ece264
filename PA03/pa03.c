#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "answer03.h"


int main(int argc, char * * argv)
{
  char * str1 = malloc(4);
  strcpy(str1, "one");
    const char * str2 = "two";
    int n = strlen(str1);
    strcat_ex(&str1,&n,str2);
    printf("'%s'\n", str1);
    free(str1);

    return EXIT_SUCCESS;
}


