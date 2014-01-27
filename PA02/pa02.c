#include <stdio.h>
#include "answer02.h"

int main(int argc, char * * argv)
{
    char* test1 = "Hello World!";
    char* test2 = "\n\vhell-1233";
    char* test3 = "Hello ";
    char* test4 = "!";
    char buffer[50];
    printf("Hello World!\n");
   // Create your test-cases here, good luck!
    /*printf("length = %zu\n",my_strlen(test1));
    printf("cnt = %d\n",my_countchar(test1,'o'));
    printf("%s\n",my_strchr(test1,'\0'));
    printf("%s\n",my_strrchr(test1,'o'));
    printf("%s\n",my_strstr(test1,test4));*/
    printf("%s\n",my_strcpy(buffer,test3));
    printf("%s\n",my_strcat(buffer,"World!"));
    printf("num = %d\n",my_atoi(test2));
    return 0;

   
}
