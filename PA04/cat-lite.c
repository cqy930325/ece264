#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void help_message(){
  printf("</help-message>\n"
         "Usage: cat-lite [--help] [FILE]...\n"
         "With no FILE, or when FILE is -, read standard input.\n"
         "\n"
         "Examples:\n"
           "cat-lite README   Print the file README to standard output.\n"
           "cat-lite f - g    Print f's contents, then standard input,\n" 
                             "then g's contents.\n"
	 "cat-lite          Copy standard input to standard output.\n"
         "</help-message>\n");
}

int printfile(const char* filename, FILE* fout){
  FILE *fin;
  if(strcmp(filename, "-") == 0) fin = stdin;
  else fin = fopen(filename, "r");
  if (fin == NULL) return 0;
  int ch;
  while ((ch = fgetc(fin)) != EOF){
    printf("%c",ch);
  }
  return 1;
}

int main(int argc, char** argv)
{
  int i;
  for(i = 1; i < argc; i++){
    if(strcmp(argv[i],"--help") == 0){
      help_message();
      return EXIT_SUCCESS;
    }
  }
  if(argc == 1){
    FILE *fin = stdin;
    int ch;
    while ((ch = fgetc(fin)) != EOF){
    printf("%c",ch);
    }
    return EXIT_SUCCESS;
  }
  for(i = 1; i < argc; i++){
    if(!printfile(argv[i],stdout)){
      fprintf(stderr, "cat cannot open %s\n",argv[i]);
      return EXIT_FAILURE;
    }
  }
  return EXIT_SUCCESS;
}
