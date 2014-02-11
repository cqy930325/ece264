#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "answer03.h"

char * strcat_ex(char * * dest, int * n, const char * src){
  char* buffer;
  int destlen;
  if(*dest == NULL){
    destlen = 0;
  }else{
    destlen = strlen(*dest);
  }
  if(*dest == NULL || *n < destlen + strlen(src) + 1){
    buffer = malloc((1 + 2 * (destlen + strlen(src))) * sizeof(char));
    *buffer = '\0';
    *n = 1 + 2 * (destlen + strlen(src));
    if(*dest != NULL){
      strcpy(buffer,*dest);
      free(*dest);
    }    
    *dest = buffer;
  }
  strcat(*dest,src);
  return *dest;
}

char * * explode(const char * str, const char * delims, int * arrLen){
  int ind = 0;
  int index1 = 0;
  int temp = 0;
  int n = 1;
  char * * ans;
  while(ind < strlen(str)){
    if(strchr(delims,str[ind]) != NULL){
      n++;
    }
    ind++;
  }
  ans =  malloc(n * sizeof(char*) );
  ind = 0;
  while(ind <= strlen(str)){
    if(strchr(delims,str[ind]) != NULL || str[ind] == 0){
      ans[index1] = malloc(sizeof(char) * (ind - temp + 1));
      memcpy(ans[index1],str+temp,ind - temp);
      ans[index1][ind-temp] = '\0';
      index1++;
      temp = ind + 1;
    }
    ind++;
  }
   *arrLen = n;
  return ans;
}
char * implode(char * * strArr, int len, const char * glue){
  int i = 0;
  // char* buffer = malloc(sizeof(char));
  char* buffer = NULL;
  int length = 0;
  for(i = 0; i < len; i++){  
    strcat_ex(&buffer,&length,strArr[i]);
    if(i != len -1){
      strcat_ex(&buffer,&length,glue);    
    }
  }
  return buffer;
}

int compare (const void *a, const void *b){
  const char **ia = (const char **)a;
  const char **ib = (const char **)b; 
  return(strcmp(*ia,*ib));
}
void sortStringArray(char * * arrString, int len){
  qsort(arrString, len,sizeof(char*),compare);
}
int compare1 (const void *a, const void *b){
  const char *ia = (const char*)a;
  const char *ib = (const char*)b;
  return(*ia - *ib);
}
void sortStringCharacters(char * str){
  if(str != NULL){
    qsort(str,strlen(str),sizeof(char),compare1);
  }
}
void destroyStringArray(char * * strArr, int len){
  int i = 0;
  if(strArr != NULL || len != 0){
    for(i = 0;i < len;i++){
      free(strArr[i]);
    }
    free(strArr);
  }
}

