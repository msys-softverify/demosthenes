/**
  * Demonstration of freed memory usage 
  */

#include <stdlib.h>
#include <stdio.h>

float get_average(int* ptr, int n) {
    long int sum = 0;
    int i;
    for (i = 0; i< n; i++) {
        sum += ptr[i];
    }
    /* this function takes responsibility to free the integer array */
    free(ptr);
    
    /* Modify an array element just to demonstrate tracking of freed memory dereference */
    ptr[0] = 0;
    
    return ((float)sum)/n;
}

void count_average_of_fibonacci(int n) {
    int* fibs;
    float avg;
	int i;
    
    if (n < 2) {
        avg = 1.0;
    } else {
        fibs = (int*)malloc(n * sizeof(int));
        if (fibs == 0) {
            abort(); /* this is low memory situation */
            /* Klocwork analysis knows that this function aborts execution so it will not issue NPDs later */
        }
        fibs[0] = 1;
        fibs[1] = 1;
        for (i = 2; i < n ; i++) {
            fibs[i] = fibs[i-1] + fibs[i-2];
        }
        avg = get_average(fibs, n);
        

        /* but calling function wants to free this array too, so we get 
           interprocedural double freeing */
        free(fibs);
    }
    printf("Average of %u Fibonacci numbers is %f\n", n, avg);
}
