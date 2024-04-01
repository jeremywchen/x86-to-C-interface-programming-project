#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern void dot_product_asm(float* A, float* B, int n, float* Sdot_asm);


void dot_product_c(float* A, float* B, int n, float* Sdot_c) {
    double sdot = 0;
    for (int i = 0; i < n; i++) {
        sdot += (double)A[i] * B[i];
    }
    *Sdot_c = (float)sdot;
}

int main() {

    // TO-DO: When done testing loop through {20, 24, 30} 30 times
    int n = pow(2, 30);

    float* A = (float*)malloc(n * sizeof(float));
    float* B = (float*)malloc(n * sizeof(float));
    float Sdot_asm;
    float Sdot_c;

    for (int j = 0; j < n; ++j) {
        A[j] = j + 1;
        B[j] = j + 1;
    }

    clock_t start_c = clock();
    dot_product_c(A, B, n, &Sdot_c);
    clock_t end_c = clock();
    double time_c = ((double)(end_c - start_c)) / CLOCKS_PER_SEC;


    
    clock_t start_asm = clock();
    dot_product_asm(A, B, n, &Sdot_asm);
    clock_t end_asm = clock();
    double time_asm = ((double)(end_asm - start_asm)) / CLOCKS_PER_SEC;

    printf("---------------------------------------------------------------------\n");

    printf("| Method          | %-30s | Execution Time |\n", "Dot Product");
    printf("|-----------------|--------------------------------|----------------|\n");
    printf("| C               | %30.2f | %14.6f |\n", Sdot_c, time_c);
    printf("| Assembly        | %30.2f | %14.6f |\n", Sdot_asm, time_asm);
    printf("---------------------------------------------------------------------\n");

    if (Sdot_asm == Sdot_c) {
        printf("| %-65s |\n", "[CORRECT] Results are correct and congruent.");
    } else {
        printf("[WRONG] Results do not match.");
    }

    printf("|-------------------------------------------------------------------|\n");




    free(A);
    free(B);

    return 0;
}