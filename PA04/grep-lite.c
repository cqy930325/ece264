#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR 2;
void printhelp(){
  printf(
         "Usage: grep-lite [OPTION]... PATTERN\n"
         "Search for PATTERN in standard input. PATTERN is a\n"
         "string. grep-lite will search standard input line by\n"
         "line, and (by default) print out those lines which\n"
         "contain pattern as a substring.\n"
         "\n"
         "  -v, --invert-match print non-matching lines\n"
         "  -n, --line-number print line number with output\n"
         "  -q, --quiet suppress all output\n"
         "\n"  
         "Exit status is 0 if any line is selected, 1 otherwise;\n"
         "if any error occurs, then the exit status is 2.\n"
         );
}
int main(int argc, char** argv){
  int i;
  int help = 0;
  int invert = 0;
  int line = 0;
  int quiet = 0;
  const char* pattern = argv[argc - 1];
  for(i = 1; i < argc - 1; i++){
    if(strcmp(argv[i],"--help")==0) help = 1;
    else if((strcmp(argv[i],"--invert-match") ==0) || (strcmp(argv[i],"-v") == 0))  invert = 1;
    else if ((strcmp(argv[i],"--line-number") == 0) ||(strcmp(argv[i],"-n") == 0) ) line = 1;
    else if ((strcmp(argv[i],"--quiet") == 0) || (strcmp(argv[i],"-q") == 0)) quiet = 1;
    else {
      fprintf(stderr,"error!\n");
      return ERROR;
    }
  }
  if(help || strcmp(pattern,"--help") == 0){
    printhelp();
    return EXIT_SUCCESS;
  }
  if(argc == 1){
    fprintf(stderr,"error!\n");
    return ERROR;
  }
  char buffer[2001];
  int found = 0;
  int lines = 0;
  while(fgets(buffer, 2001,stdin) != NULL){
    lines++;
    int matches = strstr(buffer, pattern) != NULL;
    if ((matches && !invert) || (!matches && invert)){
      found = 1;
      if(!quiet){
        if(line) printf("%d:", lines);
        printf("%s",buffer);
      }
    }
  }
  return found ? 0 : 1;
}
