#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "answer06.h"
#define FALSE 0
#define TRUE 1

/**
 * Prints all the partitions of a positive integer value.
 *
 * Example:
 * partitionAll(3); // prints the following: (line order not important)
 * = 1 + 1 + 1
 * = 1 + 2
 * = 2 + 1
 * = 3
 *
 * Note: Order does not matter, and neither does white-space. 
 * Hint: look at file: expected/partitionAll.output
 */
void printall(int* numarr,int pos){
  int i;
  for(i=0;i<pos;i++){
    if(i == 0){
      printf("= %d",numarr[i]);
    }else{
      printf(" + %d",numarr[i]);
    }
  }
  printf("\n");
}
void partitionAllrec(int head,int*numarr,int pos){
  int i;
  //basecase
  if(head == 0){
    printall(numarr,pos);
    return;
  }
  for(i = 1;i <= head;i++){
    numarr[pos] = i;
    partitionAllrec(head - i,numarr,pos+1);
  }
  
}
void partitionAll(int value){
  int *numarr = malloc(sizeof(int) * value);
  partitionAllrec(value,numarr,0);
  free(numarr);
}

/**
 * Prints all partitions that have strictly increasing values.
 *
 * Example:
 * partitionIncreasing(5); // prints the following: (line order not important)
 * = 1 + 4
 * = 2 + 3
 * = 5
 * 
 * These partitions are excluded because they are not _strictly_ increasing
 * 1 + 1 + 3
 * 2 + 1 + 2
 * 3 + 2
 * 
 * Note:
 * The program should generate only valid partitions.  Do not
 * generates all partitions and then filter for validity. If you 
 * do this, you will almost certainly have trouble understanding the exam.
 *
 * Hint: look at file: expected/partitionIncreasing.output
 */
void partitionIncreasingrec(int head,int*numarr,int pos){
  int i;
  //basecase
  if(head == 0){
    printall(numarr,pos);
    return;
  }
  for(i = 1;i <= head;i++){
    if(pos==0||i>numarr[pos-1]){  
      numarr[pos] = i;
      partitionIncreasingrec(head - i,numarr,pos+1);
    }
  }
  
}
void partitionIncreasing(int value){
   int *numarr = malloc(sizeof(int) * value);
   partitionIncreasingrec(value,numarr,0);
  free(numarr);
}

/**
 * Prints all partitions that have strictly decreasing values.
 *
 * Example:
 * partitionDecreasing(5); // prints the following: (line order not important)
 * = 3 + 2
 * = 4 + 1
 * = 5
 * 
 * These partitions are excluded because they are not _strictly_ decreasing
 * 1 + 1 + 3
 * 2 + 1 + 2
 * 
 * See: note on partitionIncreasing(...)
 * Hint: look at file: expected/partitionDecreasing.output
 */
void partitionDecreasingrec(int head,int*numarr,int pos){
  int i;
  //basecase
  if(head == 0){
    printall(numarr,pos);
    return;
  }
  for(i = 1;i <= head;i++){
    if(pos==0||i<numarr[pos-1]){  
      numarr[pos] = i;
      partitionDecreasingrec(head - i,numarr,pos+1);
    }
  }
  
}
void partitionDecreasing(int value){
  int *numarr = malloc(sizeof(int) * value);
   partitionDecreasingrec(value,numarr,0);
   free(numarr);
}

/**
 * Prints all partitions comprised solely of odd numbers.
 *
 * Example:
 * partitionOdd(5); // prints the following (line order not important)
 * = 1 + 1 + 1 + 1 + 1
 * = 1 + 1 + 3
 * = 1 + 3 + 1
 * = 3 + 1 + 1
 * = 5
 * 
 * See: note on partitionIncreasing(...)
 * Hint: for odd numbers, (value % 2 != 0)
 * Hint: look at file: expected/partitionOdd.output
 */
void partitionOddrec(int head,int*numarr,int pos){
  int i;
  //basecase
  if(head == 0){
    printall(numarr,pos);
    return;
  }
  for(i = 1;i <= head;i++){
    if(i % 2 == 1){  
      numarr[pos] = i;
      partitionOddrec(head - i,numarr,pos+1);
    }
  }
  
}
void partitionOdd(int value){
 int *numarr = malloc(sizeof(int) * value);
   partitionOddrec(value,numarr,0);
   free(numarr);
}

/**
 * Prints all partitions comprised solely of even numbers.
 *
 * Example:
 * partitionEven(6); // prints the following (line order not important)
 * = 2 + 2 + 2
 * = 2 + 4
 * = 4 + 2
 * = 6
 * 
 * See: note on partitionIncreasing(...)
 * Hint: for even numbers, (value % 2 == 0)
 * Hint: you can never partition an odd number with even numbers alone.
 * Hint: look at file: expected/partitionEven.output
 */
void partitionEvenrec(int head,int*numarr,int pos){
  int i;
  //basecase
  if(head == 0){
    printall(numarr,pos);
    return;
  }
  for(i = 1;i <= head;i++){
    if(i % 2 == 0){  
      numarr[pos] = i;
      partitionEvenrec(head - i,numarr,pos+1);
    }
  }
}
void partitionEven(int value){
 int *numarr = malloc(sizeof(int) * value);
   partitionEvenrec(value,numarr,0);
   free(numarr);
}

/**
 * Prints all partitions that do not have consecutive odd or even numbers.
 * In other words, it only prints partitions that have alternating odd and 
 * even numbers.
 *
 * Example:
 * partitionOddAndEven(5); // prints the following (line order not important)
 * = 1 + 4
 * = 2 + 1 + 2
 * = 2 + 3
 * = 3 + 2
 * = 4 + 1
 * = 5
 *
 * See: note on partitionIncreasing(...)
 * Hint: look at file: expected/partitionOddAndEven.output
 */
void partitionOddAndEvenrec(int head,int*numarr,int pos){
  int i;
  //basecase
  if(head == 0){
    printall(numarr,pos);
    return;
  }
  for(i = 1;i <= head;i++){
    if(pos == 0 || (i % 2)  != (numarr[pos-1] % 2)){  
      numarr[pos] = i;
      partitionOddAndEvenrec(head - i,numarr,pos+1);
    }
  }
}
void partitionOddAndEven(int value){
 int *numarr = malloc(sizeof(int) * value);
   partitionOddAndEvenrec(value,numarr,0);
   free(numarr);
}



/**
 * Prints all partitions that comprise solely of prime numbers.
 *
 * Example:
 * partitionPrime(5); // prints the following (line order not important)
 * = 2 + 3
 * = 3 + 2
 * = 5
 * 
 * See: note on partitionIncreasing(...)
 * Hint: you will need to write a function that checks if a number is prime.
 * Hint: 1 is not a prime number.
 * Hint: look at file: expected/partitionPrime.output
 */
int isPrime(int n){
  int i;
  if(n == 1){
    return 0;
  }
  if(n == 2){
    return 1;
  }
  for(i = 2; i <= n/2; i++){
    if(n % i == 0){
      return 0;
    }
  }
  return 1;
}
void partitionPrimerec(int head,int*numarr,int pos){
  int i;
  //basecase
  if(head == 0){
    printall(numarr,pos);
    return;
  }
  for(i = 1;i <= head;i++){
    if(isPrime(i)){  
      numarr[pos] = i;
      partitionPrimerec(head - i,numarr,pos+1);
    }
  }
}
void partitionPrime(int value){
 int *numarr = malloc(sizeof(int) * value);
   partitionPrimerec(value,numarr,0);
   free(numarr);
}

