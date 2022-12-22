#include <pthread.h>
#include <stdlib.h>
#include <stdio.h> 
#include <unistd.h>

   struct variable_add {
   	int a;
   	int b;
   };

void *add(void *sum) {
    
   sleep(1);
   struct variable_add *s= sum;
   printf("\n[THREAD] Sum of %d and %d is %d",s->a,s->b,s->a+s->b);
   pthread_exit(NULL);
   
}
   

int main () {

   // thread defintion
   pthread_t threads;
   
   
   int result;
   
   struct variable_add s;
   s.a=10;
   s.b=15;

   
      printf("\n[MAIN] Creating thread");
      
      result = pthread_create(&threads, NULL, add,&s);
      
      if (result) {
      
         printf("Error in creating thread, %d ", result);
         exit(-1);
      }
      

   pthread_exit(NULL);
   return 0;
}
