#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "answer03.h"


int main(int argc, char * * argv)
{
  //test for strcat_ex
  char * str1 = malloc(4);
  strcpy(str1, "one");
  const char * str2 = "two";
  int n = strlen(str1);
  strcat_ex(&str1,&n,str2);
  printf("'%s'\n", str1);
  free(str1);
  //test for explode
  int arrlen = 0;
  int i = 0;
  char** ans = explode("helloxxbeautiful!world lol","x !",&arrlen);
  sortStringArray(ans,arrlen);
  for(i = 0; i < arrlen; i++){
    //printf("%s ",ans[i]);
  }
  printf("%d words\n",arrlen);
  char* haha = implode(ans,arrlen,"5");
  destroyStringArray(ans,arrlen);
  printf("%s\n",haha);
  sortStringCharacters(haha);
  printf("%s\n",haha);
  free (haha);
  return EXIT_SUCCESS;
}


