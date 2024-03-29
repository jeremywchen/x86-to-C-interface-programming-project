#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern float dot_product_asm(int* A, int* B, int n);


double dot_product_c(int* A, int* B, int n) {
    double sdot = 0;
    for (int i = 0; i < n; i++) {
        sdot += (double)A[i] * B[i];
    }
    return sdot;
}

int main() {
   
    // TO-DO: When done testing loop through {20, 24, 30} 30 times
    int n = pow(2, 30);

    unsigned int* A = (int*)malloc(n * sizeof(unsigned int));
    unsigned int* B = (int*)malloc(n * sizeof(unsigned int));


    for (int j = 0; j < n; ++j) {
        A[j] = j+1;
        B[j] = j+1;
    }
    

    clock_t start_c = clock();
    double sdot_c = dot_product_c(A, B, n);
    clock_t end_c = clock();
    double time_c = ((double)(end_c - start_c)) / CLOCKS_PER_SEC;

    clock_t start_asm = clock();
    float sdot_asm = dot_product_asm(A, B, n);
    clock_t end_asm = clock();
    double time_asm = ((double)(end_asm - start_asm)) / CLOCKS_PER_SEC;


    printf("\Sdot (C): %lf\n", sdot_c);

    // TO-DO: make assembly return the value (might need to use double?)
    //printf("Dot product (Assembly): %f\n", sdot_asm);
    printf("Execution time (C): %f seconds\n", time_c);
    printf("Execution time (Assembly): %f seconds\n\n", time_asm);


    free(A);
    free(B);

    return 0;
}
