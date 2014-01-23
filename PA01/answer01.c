#include <stdlib.h>
#include "answer01.h"

int arraySum(int * array, int len)
{ 
  int sum = 0;
  int i;
  for(i = 0;i < len;i++){
    sum = sum+array[i];
  }
  return sum;
}

int arrayCountNegative(int * array, int len)
{
  int cnt = 0;
  int i;
  for(i = 0;i < len;i++){
    if(array[i] < 0){
      cnt++;
    }
  }
  return cnt;
}

int arrayIsIncreasing(int * array, int len)
{    
  int i;
  for(i = 0;i < len - 1;i++){
    if(array[i]>array[i+1]){
      return 0;
    }
  }
  return 1;
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
  int i;
  int index = -1;
  for(i = 0;i < len;i++){
    if(haystack[i] == needle){
      index = i;
    }
  }
  return index;
}

int arrayFindSmallest(int * array, int len)
{
  int index = 0;
  int i;
  for(i = 1;i < len;i++){
    if(array[i] < array[index]){
      index = i;
    } 
  }
  return index;
}
