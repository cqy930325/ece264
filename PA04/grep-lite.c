#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR 2;
#define STRSIZE 2001;
int main(int argc, char** argv){
  int i;
  int help = 0;
  int invert = 0;
  int line = 0;
  int quiet = 0;
  const char* *pattern = argv[argc - 1];
  #define ARGCMP(S) strcmp((argv[i],S)==0);
  for(i = 1; i < argc - 1; i++){
    if(strcmp(argv[i],"--help")==0) help = 1;
    else if(strcmp(argv[i],"--invert-match" ==0) || strcmp(argv[i],"-v"==0))invert = 1;  
    else if (ARGCMP("--line-number")) line = 1;
    else if (ARGCMP("--quiet")) quiet = 1;
    else {
      fprintf(stderr,"error!\n");
      return ERROR;
    }
  }
  if(help || strcmp(pattern,"--help") == 0){
    printhelp();	
  }
  if(argc == 1){
    fprintf(stderr,"error!\n);
    return ERROR;
  }
  char buffer[STRSIZE];
  int found = 0;
  int lines = 0;
  while(fgets(buffer, STRSIZE,stdin) != NULL){
    line++;
    int matches = strstr(buffer, pattern) != NULL;
    if (matches && !invert || !matches && !invert){
      found = 1;
      if(!quiet){
        if(!line) printf("%d:", lines);
        printf("%s",buffer);
      }
    }
  }
  return found ? 0 : 1;
}
