#include <stdlib.h>
#include "answer02.h"
size_t my_strlen(const char * str){
  int len = 0;
  while(str[len] != '\0'){
    len++;
  }
  return len;
}

int my_countchar(const char * str, char ch){
  int i;
  int cnt = 0;
  for(i = 0;i < my_strlen(str);i++){
    if (str[i] == ch){
      cnt++;
    }
  }
  return cnt;
}

char *my_strchr(const char * str, int ch){
  int i;
  for(i = 0;i <= my_strlen(str);i++){
    if (str[i] == ch){
      
      return (char*)(str + i);
    }
  }
    return NULL;
}

char * my_strrchr(const char * str, int ch){
  int i;
  char* pointer;
  pointer = NULL;
  for(i = 0;i <= my_strlen(str);i++){
    if (str[i] == ch){
      pointer =  (char*)(str + i);
    }
  }
  return pointer;
}
char * my_strstr(const char * haystack, const char * needle){
  int hlen = my_strlen(haystack);
  int nlen = my_strlen(needle);
  int i;
  int j;
  if(nlen ==0){
    return (char*)haystack;
  }
  if (hlen == 0){
    return NULL;
  }
  for(i=0;i <= (hlen - nlen);i++){
    for(j = 0;j < nlen;j++){
      if(haystack[i+j] != needle[j]){
	j = j + nlen; 
      }else if(j == nlen -1){
	return (char*)(haystack + i);
      }
    }
  }
  return NULL;
}

char * my_strcpy(char * dest, const char * src){
  int i;
  for(i = 0;i <= my_strlen(src);i++){
    dest[i] = src[i]; 
  }
  return dest;
}

char * my_strcat(char * dest, const char * src){
  int i = 0;
  int j = 0;
  while(dest[i] != '\0'){
    i++;
  }
  for(j = 0;j <= my_strlen(src);j++){
    dest[j+i] = src[j]; 
  }
  return dest;
}


int my_isspace(int ch){
  if((ch > 8 && ch <14)|| ch == 32){
    return 1;
  }
  return 0;
}

int my_atoi(const char * str){
  int i = 0;
  int neg = 0;
  int ret = 0;
  int len = my_strlen(str);
  while(i < len){   
    if(str[i] == '-'){
      neg = 1;
    }
    if(str[i] >= '0' && str[i] <= '9'){
      ret = ret * 10;
      ret = ret + str[i] - '0';
    }
    i++;
  }
  if (neg == 1){
    ret = ret * -1;
  }
  return ret;
  
}




